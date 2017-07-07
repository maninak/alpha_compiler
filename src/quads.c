#ifndef _QUADS_C_
#define _QUADS_C_

#include "../include/quads.h"


Quad * quads = NULL;	// The data structure containing all the quads emitted
//quads = NULL;
unsigned total = 0;		// The maximum capacity of the array
unsigned currQuad = 0;	// The next empty slot in the array to input a quad

unsigned nextquadlabel() { return currQuad; }

void emit (
	IOPCODE	op,
	Expr* 	arg1,
	Expr* 	arg2,
	Expr* 	result,
	unsigned label
	){
	
        //printf("currQuad=%d total=%d\n", currQuad, total); //TODO delete
	if (currQuad == total){ expand(); }

	Quad * p 	= quads + currQuad++;
	p->op 		= op;
	p->arg1 	= arg1;
	p->arg2 	= arg2;
	p->result 	= result;
	p->label 	= label;
	p->line 	= yylineno;
        
	quads[currQuad] = *p;
}

Expr * emit_iftableitem (Expr * e){
	assert(e);
	if (e->type != tableitem_e){
		return e;
	}
	else {
		Expr * result = newexpr(var_e);
		result->sym = newtemp();
		emit(tablegetelem, e, e->index, result, 0);
		return result;
	}
}

void expand (){
	assert(total == currQuad);

	Quad * p = (Quad *) malloc(NEW_SIZE);
	assert(p); //TODO delete
	if (quads) {
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads = p;
	total += EXPAND_SIZE;
}

Expr * member_item (Expr * lvalue, char * name){
	lvalue = emit_iftableitem(lvalue);
	Expr* item = newexpr(tableitem_e);
	item->sym = lvalue->sym;
	item->index = newexpr_conststring(name);
	// TODO might need freeExpression(lvalue);
	return item;
}

Expr * make_call (struct Expr * lvalue, struct ExprList * elist){
	assert(lvalue);
	assert(elist);
	
	Expr * func = emit_iftableitem(lvalue);
	ExprNode * cur = elist->head;
	while (cur != NULL){
		emit(param, cur->expr, NULL, NULL, 0);
		cur = cur->prev;
	}
	emit(call, func, NULL, NULL, 0);
	Expr * result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval, result, NULL, NULL, 0);
	return result;
}

void backpatch (IntStack * list, unsigned label){
	if (list == NULL) { return; }

	Quad * q;
	while (!isEmptyIntStack(list)){ // for every integer in the list provided TODO for i<i=listsize()
		 q = & quads[popInt(list)]; // get the quad in that position
		 q->label = label; 			// Patch the jump destination
		 printf("Quad was patched with label: %d\n", q->label); //TODO delete
	}
}


void patchlabel (unsigned quadNo, int label){
	quads[quadNo].label = label;
}

int print_const (Expr * e){
	assert(e);
	
	int tempInt;
	char buf[20];

	switch (e->type){
		case stringconst_e:
			printf("\"%s\"",e->strconst);
			tempInt = strlen(e->strconst);
			tempInt = tempInt +2;
			break;
		case numconst_e:
			printf("%f",e->numconst);
			sprintf(buf,"%f",e->numconst);
			tempInt = strlen(buf);
			break;
		case boolconst_e:
			if (e->boolconst==0){
				printf("false");
				tempInt = 5;
			}
			else{
				printf("true");
				tempInt = 4;
			}
			break;
		case nil_e:
			printf("nil");
			tempInt = 3;
			break;
		default: assert(0);
	}
	return tempInt;
}

char * OPtoString (IOPCODE op){ // TODO optimize: bring most common cases to top
	switch(op){
	  case assign:		return "assign";		break;
	  case add:		return "add";			break;
	  case sub:		return "sub";			break;
	  case mul:		return "mul";			break;
	  case divide:		return "div";			break;
	  case mod:		return "mod";			break;
	  case uminus:		return "uminus";		break;
	  case if_eq:		return "if_eq";			break;
	  case if_noteq:	return "if_noteq";		break;
	  case if_lesseq:	return "if_lesseq";		break;
	  case if_greatereq:    return "if_greatereq";          break;
	  case if_less:		return "if_less";		break;
	  case if_greater:	return "if_greater";            break;
	  case call:		return "call";			break;
	  case param:		return "param";			break;
	  case ret:		return "ret";			break;
	  case getretval:	return "getretval";		break;
	  case funcstart:	return "funcstart";		break;
	  case funcend:		return "funcend";		break;
	  case tablecreate:	return "tablecreate";           break;
	  case tablegetelem:    return "tablegetelem";          break;
	  case tablesetelem:    return "tablesetelem";          break;
	  case jump:		return "jump";			break;
	  default:		assert(0);      return NULL; //returns just to bypass warning
	}
}

void printQuads(){
	int 	i, z;
	Quad	tempQuad;
	char 	buf[100];

	printf("\n--- QUAD INSTRUCTIONS PRINTOUT ---------------------------------------------------------------\n");
        printf("Quad      OpCode              Arg1                Arg2                Result             Label\n");
	printf("----------------------------------------------------------------------------------------------\n");
  	printf("Total Quads = %u\n\n", currQuad);

	for(i=0; i < currQuad; i++){
		tempQuad = quads[i];
		if (tempQuad.op == emptyquad) continue;

		// Print quad's number
		printf("%d:", i);
		sprintf(buf,"%d:", i);
		z = strlen(buf);
		for (; z<10; z++) { printf(" "); }

		// Print quad's OpCode
		printf("%s",OPtoString(tempQuad.op));
		for (z = strlen(OPtoString(tempQuad.op)); z<20; z++){ printf(" "); }

		// Print quad's Arg1 field
		if (tempQuad.arg1 != NULL){
			if (   (tempQuad.arg1)->type == stringconst_e 
				|| (tempQuad.arg1)->type == numconst_e
				|| (tempQuad.arg1)->type == boolconst_e
				|| (tempQuad.arg1)->type == nil_e){
				z = print_const(tempQuad.arg1);
			}
			else {
				assert(tempQuad.arg1->sym);
				printf("%s", tempQuad.arg1->sym->name);
				z = strlen(tempQuad.arg1->sym->name);
			}
			for(; z<20; z++) { printf(" "); }
		}
		else { printf("                    "); }

		// Print quad's Arg2 field
		if (tempQuad.arg2 != NULL){
			if (   (tempQuad.arg2)->type == stringconst_e 
				|| (tempQuad.arg2)->type == numconst_e
				|| (tempQuad.arg2)->type == boolconst_e
				|| (tempQuad.arg2)->type == nil_e){
				z = print_const(tempQuad.arg2);
			}
			else {
				assert(tempQuad.arg2->sym);
				printf("%s",(((tempQuad.arg2))->sym)->name);
				z=strlen((((tempQuad.arg2))->sym)->name);
			}
			for(; z<20; z++) {printf(" ");}

		}
		else { printf("                    "); }

		// Print quad's Result field
		if (tempQuad.result != NULL){
			if ((tempQuad.result)->sym != NULL){
				printf("%s",(((tempQuad.result))->sym)->name);
				z=strlen((((tempQuad.result))->sym)->name);
			}
			else { z = print_const(tempQuad.result); }
			for (; z<19; z++) { printf(" "); }
		}
		else { printf("                   "); }

		// Print quad's Label
		if (tempQuad.label != 0) 	{ printf("%d\n",tempQuad.label); }
		else 						{ printf("\n");}
	}
}

#endif
