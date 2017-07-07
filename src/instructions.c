#ifndef _INSTRUCTIONS_C_
#define _INSTRUCTIONS_C_
#include "../include/instructions.h"


IncompleteJump *  ij_head  = (IncompleteJump*) 0;   //Head to the incomplete_jumps trivial list
unsigned          ij_total = 0;                     //Counter that keeps how many ijs are in the list

Instruction *     instructions = NULL;              // The data structure containing all the quads emitted
unsigned          total_I = 0;                      // The maximum capacity of the array
unsigned          currInstruction = 0;              // The next empty slot in the array to input a quad

unsigned nextinstructionlabel(){ 
    return currInstruction; 
}

void emit_I (Instruction t){
  if (currInstruction == total_I){ expand_I(); }

  Instruction * p         = instructions + currInstruction++;
  p->opcode               = t.opcode;
  p->arg1                 = t.arg1;
  p->arg2                 = t.arg2;
  p->result               = t.result;
  p->srcLine              = t.srcLine;
  instructions[currInstruction] = *p;
}

void expand_I (){
  assert(total_I == currInstruction);

  Instruction* t = (Instruction *) malloc(NEW_SIZE_I);
  assert(t);
  if (instructions) {
    memcpy(t, instructions, CURR_SIZE_I);
    free(instructions);
  }
  instructions = t;
  total_I += EXPAND_SIZE_I;
}

void add_incomplete_jump(unsigned instrNo,unsigned iaddress){
  IncompleteJump * new = (IncompleteJump*) malloc(sizeof(IncompleteJump));
  IncompleteJump * trav = (IncompleteJump* )malloc(sizeof(IncompleteJump));

  new->instrNo = instrNo;
  new->iaddress = iaddress;
  if (ij_head == NULL){
    ij_head = new;
    new->next = NULL;
    ij_total++;
  }
  else{
    trav = ij_head;

    while (trav->next != NULL){
      trav=trav->next;
    }

    trav->next = new;
    new->next = NULL;
    ij_total++;
  }
}

void patch_incomplete_jumps(){
  IncompleteJump* traverse;
  traverse = ij_head;

  while (traverse != NULL){
    if (traverse->iaddress == currQuad ){
      instructions[traverse->instrNo].result.val = currInstruction;
    }
    else {
      instructions[traverse->instrNo].result.val = quads[traverse->iaddress].taddress;
    }
    traverse=traverse->next;
  }
}

char * VMOPtoString (VMOPCODE op){ // TODO optimize: bring most common cases to top
  switch (op){
    case assign_v:        return "assign";            break;
    case add_v:           return "add";               break;
    case sub_v:           return "sub";               break;
    case mul_v:           return "mul";               break;
    case div_v:           return "div";               break;
    case mod_v:           return "mod";               break;
    case uminus_v:        return "uminus";            break;
    case jeq_v:           return "if_eq";             break;
    case jne_v:           return "if_noteq";          break;
    case jle_v:           return "if_lesseq";         break;
    case jge_v:           return "if_greatereq";      break;
    case jlt_v:           return "if_less";           break;
    case jgt_v:           return "if_greater";        break;
    case call_v:          return "call";              break;
    case param_v:         return "param";             break;
    case ret_v:           return "ret";               break;
    case getretval_v:     return "getretval";         break;
    case enterfunc_v:     return "enterfunc";         break;
    case exitfunc_v:      return "exitfunc";          break;
    case tablecreate_v:   return "tablecreate";       break;
    case tablegetelem_v:  return "tablegetelem";      break;
    case tablesetelem_v:  return "tablesetelem";      break;
    case jump_v:          return "jump";              break;
    case emptyquad_v:     return "empty";             break;
    case pusharg_v:       return "pusharg";           break;
    case callfunc_v:      return "callfunc";          break;
    case nop_v:           return "nop";               break;
    default: assert(0);   return NULL;
  }
}
char * VMATtoString (VMARG_TYPE type){ // VMARGTYPE
  switch (type){
    case programfunc_a:     return "programfunc";     break;
    case libfunc_a:         return "libfunc";         break;
    case retval_a:          return "retval";          break;
    case global_a:          return "global";          break;
    case local_a:           return "local";           break;
    case label_a:           return "label";           break;
    case formal_a:          return "formal";          break;
    case number_a:          return "number";          break;
    case bool_a:            return "bool";            break;
    case string_a:          return "string";          break;
    case nil_a:             return "nil";             break;
    case empty_a:           return "empty";           break;
    default: assert(0);     return NULL; 
  }
}

void printInstructions(){
  char *  inNum   = "Inst";
  int     inNo    = 4;
  char *  op      = "OP";
  char *  arg1    = "Arg1";
  char *  arg2    = "Arg2";
  char *  result  = "Result";
  
  unsigned i;
  int col1,col2;  //Vars for alligning.The work with the asterisk(*)
  col1 = 16;
  col2 = 15;
  
  printf("INSTRUCTIONS\n");
  printf("%*s%*s%*s%*s\t%*s\t  Line",inNo,inNum,col1,op,col2,arg1,col2,arg2,col2,result);
  for (i=0; i < currInstruction; i++){

    printf("\n%*d%*s",inNo,i,col1,VMOPtoString(instructions[i].opcode));
    if (strcmp(VMATtoString(instructions[i].arg1.type),"empty")!=0){
      printf("%*s(%u)",col2,VMATtoString(instructions[i].arg1.type),instructions[i].arg1.val);
    }
    else {
      printf("%*s   ",col2,"");
    }
    if (strcmp(VMATtoString(instructions[i].arg2.type),"empty")!=0){
      printf("%*s(%u)",col2,VMATtoString(instructions[i].arg2.type),instructions[i].arg2.val);
    }
    else {
      printf("%*s   ",col2,"");
    }
    if (strcmp(VMATtoString(instructions[i].result.type),"empty")!=0){
      printf("%*s(%u)",col2,VMATtoString(instructions[i].result.type),instructions[i].result.val);
    }
    else {
      printf("%*s   ",col2,"");
    }
    printf("  %d\n",instructions[i].srcLine);
  }
}

#endif
