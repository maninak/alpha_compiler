#ifndef _GENERATOR_C_
#define _GENERATOR_C_

#include "../include/generator.h"

SymbolStack * funcStack;                //Symbol stack for keeping nested functions
unsigned current_processed_quad = 0;    //Var for keeping the number of the quad under proccess


unsigned currprocessedquad(){
    return current_processed_quad;
}

void generate(IOPCODE op,Quad* quad){
    Instruction * t ;
    t= (Instruction *)malloc(sizeof(Instruction));
    t->opcode = op;
    make_operand(quad->arg1, &t->arg1);
    make_operand(quad->arg2, &t->arg2);
    make_operand(quad->result, &t->result);
    quad->taddress = nextinstructionlabel();
    t->srcLine=quad->line;
    emit_I(*t);
}

void generate_ADD(Quad* quad){
	generate(add,quad);
}

void generate_SUB(Quad* quad){
	generate(sub,quad);
}

void generate_MUL(Quad* quad){
	generate(mul,quad);
}

void generate_DIV(Quad* quad){
	generate(div_v,quad);
}

void generate_MOD(Quad* quad){
	generate(mod,quad);
}
void generate_UMINUS(Quad* quad){
    quad->arg2 = newexpr_constnum(-1);
    generate_MUL(quad);
}

void generate_NEWTABLE(Quad* quad){
	generate(tablecreate, quad); 
}

void generate_TABLEGETELEM(Quad* quad){
	generate(tablegetelem, quad);
}

void generate_TABLESETELEM(Quad* quad){
	 generate(tablesetelem, quad); 
}

void generate_ASSIGN (Quad* quad){
	generate(assign, quad); 
}

void generate_NOP (){ 
	Instruction *t=(Instruction *)malloc(sizeof(Instruction));
	t->opcode=nop_v;
	emit_I(*t); 
} 
void generate_relational(IOPCODE op,Quad* quad) {
    
	Instruction * t=(Instruction *)malloc(sizeof(Instruction));
	t->opcode = op;
	make_operand(quad->arg1, &t->arg1);
	make_operand(quad->arg2, &t->arg2);
	t->result.type = label_a;
	if (quad->label < currprocessedquad()){

		t->result.val = quads[quad->label].taddress;
	}
	else{
		add_incomplete_jump(nextinstructionlabel(), quad->label);
	}
	quad->taddress = nextinstructionlabel();
        t->srcLine=quad->line;
	emit_I(*t);
}

void	generate_JUMP(Quad* quad){
	generate_relational(jump_v, quad);
}

void	generate_IF_EQ(Quad* quad){ 
	generate_relational(jeq_v, quad);
}

void	generate_IF_NOTEQ(Quad* quad){ 
	generate_relational(jne_v, quad); 
}

void	generate_IF_GREATER(Quad* quad){
	 generate_relational(jgt_v, quad); 
}

void	generate_IF_GREATEREQ(Quad* quad){
	 generate_relational(jge_v, quad);
}

void	generate_IF_LESS(Quad* quad){
	generate_relational(jlt_v, quad); 
}

void	generate_IF_LESSEQ(Quad* quad){ 
	generate_relational(jle_v, quad);
}

void	generate_PARAM(Quad* quad) {
	quad->taddress = nextinstructionlabel();
	Instruction * t=(Instruction *)malloc(sizeof(Instruction));
	t->opcode = pusharg_v;
	make_operand(quad->arg1, &t->arg1);
        t->srcLine=quad->line;
	emit_I(*t);
}

void generate_CALL(Quad* quad) {
	quad->taddress = nextinstructionlabel();
	Instruction * t=(Instruction *)malloc(sizeof(Instruction));
	t->opcode = callfunc_v;
	make_operand(quad->arg1, &t->arg1);
        t->srcLine=quad->line;
	emit_I(*t);
}

void generate_GETRETVAL(Quad* quad) {
	quad->taddress = nextinstructionlabel();
	Instruction * t=(Instruction *)malloc(sizeof(Instruction));
	t->opcode = assign;
	make_operand(quad->result, &t->result);
	make_retvalOperand(&t->arg1);
        t->srcLine=quad->line;
	emit_I(*t);
}

void generate_FUNCSTART(Quad* quad){
        Symbol* f=(Symbol *)malloc(sizeof(Symbol));
	assert(f);
        f=quad->arg1->sym;
	
        
	f->taddress=nextinstructionlabel();
	quad->taddress=nextinstructionlabel();
        
        /*add_new_USR(f->taddress,f->totalLocals,f->name);  TODO Maybe delete */
        if(funcStack==NULL){
            funcStack=createSymbolStack();
        }
        
        pushSymbol(funcStack,f);
        
        Instruction * t=(Instruction *)malloc(sizeof(Instruction));
        t->opcode=enterfunc_v;
        make_operand(quad->arg1,&t->result);   //TODO htan result!!
        reset_operand(&(t->arg1));
        reset_operand(&(t->arg2));
        t->srcLine=quad->line;
        emit_I(*t);
        
}
void generate_RETURN(Quad* quad){
    
    Symbol *f;
    quad->taddress=nextinstructionlabel();
    Instruction * t=(Instruction *)malloc(sizeof(Instruction));
    t->opcode=assign;
    make_retvalOperand(&t->result);
    make_operand(quad->arg1,&t->arg1);
    reset_operand(&(t->arg2));
    t->srcLine=quad->line;
    emit_I(*t);
    
    f=topSymbol (funcStack);
    if(f->returnList==NULL){
        f->returnList=createIntStack();
        pushInt(f->returnList,nextinstructionlabel());
    }
    else{
        pushInt(f->returnList,nextinstructionlabel());
    }
    
    t->opcode = jump;
    reset_operand(&(t->arg1));
    reset_operand(&t->arg2);
    t->result.type=label_a;
    t->srcLine=quad->line;
    emit_I(*t);
}
void generate_FUNCEND(Quad* quad){
    
    
    Symbol *f;
    f=popSymbol(funcStack);
    
    backpatch_I(f->returnList,nextinstructionlabel());
    quad->taddress=nextinstructionlabel();
    
    Instruction * t=(Instruction *)malloc(sizeof(Instruction));
    
    t->opcode = exitfunc_v;
    make_operand(quad->arg1,&t->result);
    reset_operand(&(t->arg1));
    reset_operand(&(t->arg2));
    t->srcLine=quad->line;
    emit_I(*t);
}
void backpatch_I(IntStack * returnList,unsigned label){
    
    while(!isEmptyIntStack(returnList)){
        
        int instrNo=popInt(returnList);
        
        instructions[instrNo].result.val=label;
    }
}
generator_func_t generators[] = {	
	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
	generate_CALL,
	generate_PARAM,
	generate_RETURN,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
        generate_JUMP,
	generate_NOP	
};

void generateInstructionTable(){
    unsigned i;
    for(i=0; i<currQuad;i++){
        
        (*generators[quads[i].op])(quads+i);
        
        current_processed_quad++;
    }
    patch_incomplete_jumps();
    
}
#endif
