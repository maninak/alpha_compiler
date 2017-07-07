#ifndef _HANDLER_C_
#define _HANDLER_C_

#include "../include/handler.h"
#include "../include/expressions.h"
#include "../include/quads.h"
#include "../include/offsets.h"
#include <math.h>

Expr* handle_expr_gr_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr > expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_greater, expr1, expr2, NULL, 0);
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

Expr* handle_expr_gr_eq_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr >= expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_greatereq, expr1, expr2, NULL, 0); //TODO lect11/6 say emit(relop), assign false, jump, assign false
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

Expr* handle_expr_ls_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr < expr\n");
	assert(expr1);
	assert(expr2);
	
	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_less, expr1, expr2, NULL, 0);
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

Expr* handle_expr_ls_eq_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr <= expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_lesseq, expr1, expr2, NULL, 0);
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

Expr* handle_expr_eq_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr == expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_eq, expr1, expr2, NULL, 0);
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

Expr* handle_expr_not_eq_expr (Expr* expr1, Expr* expr2){
	printf("expr -> expr != expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);	
	
/*
	// case {(a relop b) relop c} or {a relop (b relop c)}
	if (	(expr1->type != var_e && istempexpr(expr1)) ||
			(expr2->type != var_e && istempexpr(expr2))
			){ // TODO it emits for {x+y >= z-w} when it shouldn't
		int nextQuad = nextquadlabel();
		backpatch(E->truelist, nextQuad);
		backpatch(E->falselist, nextQuad+2);
		emit(assign, newexpr_constbool(1), NULL, E, 0);
		emit(jump, NULL, NULL, NULL, nextQuad+3);
		emit(assign, newexpr_constbool(0), NULL, E, 0);
	}
*/
	
	pushInt(E->truelist, nextquadlabel());
	emit(if_noteq, expr1, expr2, NULL, 0);
	pushInt(E->falselist, nextquadlabel());
	emit(jump, NULL, NULL, NULL, 0);
	
	return E;
}

void trueTest (Expr * expr){
	assert(expr);
	
	switch(expr->type){
		case numconst_e:
			expr->boolconst = expr->numconst != 0;
			expr->type = boolconst_e;
			break;
		case programfunc_e:
			expr->boolconst = 1;
			expr->type = boolconst_e;
			break;
		case stringconst_e:
			expr->boolconst = expr->strconst[0] != '\0';
			expr->type = boolconst_e;
			break;
		case tableitem_e: //TODO not sure if this should be here
			expr->boolconst = 1; // or this is the proper assignment
			expr->type = boolconst_e;
			break;
		case newtable_e:
			expr->boolconst = 1;
			expr->type = boolconst_e;
			break;
		case nil_e:
			expr->boolconst = 0;
			expr->type = boolconst_e;
			break;
		case libraryfunc_e:
			expr->boolconst = 1;
			expr->type = boolconst_e;
			break;
		default: break;
	}
}

int handle_boolean_M(){
	printf("boolean_M -> empty\n");
	return nextquadlabel();
}

Expr* handle_expr_and_expr (Expr* expr1, int boolean_M, Expr* expr2){
	printf("expr -> expr AND expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();	
	backpatch (expr1->truelist, boolean_M);
	E->truelist = expr2->truelist;
	E->falselist = mergeIntStacks(expr1->falselist, expr2->falselist);
	
	trueTest(expr1);
	trueTest(expr2);
	
	// if called with {true/false and true/false;}
	if ((expr1->type == boolconst_e) && (expr2->type == boolconst_e)){
		E->type = boolconst_e;
		E->boolconst = expr1->boolconst && expr2->boolconst;
		return E;
	}
	// if called with {false and x;} or {x and false;}		
	else if (((expr1->type == boolconst_e) && (expr1->boolconst == 0))
			|| ((expr2->type == boolconst_e) && (expr2->boolconst == 0))){
		E->type = boolconst_e;
		E->boolconst = 0;
		return E;
	}		
	// expr1
	// if called with {true and x;} ignore expr1 entirely
	if((expr1->type == boolconst_e) && (expr1->boolconst == 1)){}
	else {
		if (!istempexpr(expr1)){
			int nextQuad = nextquadlabel();
			emit(if_eq, expr1, newexpr_constbool(1), NULL, nextQuad+2);
			emit(jump, NULL, NULL, NULL, 0);
			pushInt(E->falselist, nextQuad+1);
		}
	} 	
	// expr2
	// if input is {x and true;} ignore expr2 entirely		
	if((expr2->type == boolconst_e) && (expr2->boolconst == 1)){}
	else if (expr2->type != boolexpr_e){
		int nextQuad = nextquadlabel();
		emit(if_eq, expr2, newexpr_constbool(1), NULL, 0);
		pushInt(E->truelist, nextQuad);
		emit(jump, NULL, NULL, NULL, 0);
		pushInt(E->falselist, nextQuad+1);
	}	
	return E;
}

Expr* handle_expr_or_expr (Expr* expr1, int boolean_M, Expr* expr2){
	printf("expr -> expr OR expr\n");
	assert(expr1);
	assert(expr2);

	Expr* E = newexpr(boolexpr_e);
	E->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();	
	backpatch (expr1->falselist, boolean_M);
	E->truelist = mergeIntStacks(expr1->truelist, expr2->truelist);
	E->falselist = expr2->falselist;
	
	trueTest(expr1);
	trueTest(expr2);
	
	// if called with {true/false or true/false;}
	if ((expr1->type == boolconst_e) && (expr2->type == boolconst_e)){
		E->type = boolconst_e;
		E->boolconst = expr1->boolconst || expr2->boolconst;
		return E;
	}
	// if called with {true or x;} or {x or true;}	
	else if (((expr1->type == boolconst_e) && (expr1->boolconst == 1))
			|| ((expr2->type == boolconst_e) && (expr2->boolconst == 1))){
		E->type = boolconst_e;
		E->boolconst = 1;
		return E;
	}		
	// expr1
	// if called with {false or x;} ignore expr1 entirely
	if((expr1->type == boolconst_e) && (expr1->boolconst == 0)){}
	else {
		if (!istempexpr(expr1)){
			emit(if_eq, expr1, newexpr_constbool(1), NULL, 0);
			pushInt(E->truelist, nextquadlabel()-1); // Do NOT move above emit (seg)
		}
	} 	
	// expr2
	// if input is {x or false;} ignore expr2 entirely		
	if((expr2->type == boolconst_e) && (expr2->boolconst == 0)){}
	else if (expr2->type != boolexpr_e){
		int nextQuad = nextquadlabel();
		emit(if_eq, expr2, newexpr_constbool(1), NULL, nextQuad+2);
		emit(jump, NULL, NULL, NULL, 0);
		pushInt(E->falselist, nextQuad+1);
	}	
	return E;
}

Expr* handle_term_not_expr (Expr* expr1){ //TODO {x=a and not b;} could be done without the 4 more emits
	printf("term -> NOT expr\n");	
	assert(expr1);

	Expr* expr = newexpr(var_e); // was boolexpr_e, seems to work
	expr->sym = istempexpr(expr1) ? expr1->sym : newtemp();	// reusing temp sym
	expr->truelist = expr1->falselist;
	expr->falselist = expr1->truelist;
	trueTest(expr1);
	
	if (expr1->type == boolconst_e){
		expr->type = boolconst_e;
		expr->boolconst = !expr1->boolconst;
	}	//case {not a;}
	else if ((expr1->type != boolexpr_e) && !istempexpr(expr1)){
		emit(if_eq, expr1, newexpr_constbool(1), NULL, nextquadlabel()+3);
		emit(assign, newexpr_constbool(1), NULL, expr, 0);
		emit(jump, NULL, NULL, NULL, nextquadlabel()+2);
		emit(assign, newexpr_constbool(0), NULL, expr, 0);
	}
	return expr;
}

Expr* handle_expr_op_expr (Expr* expr1, char op, Expr* expr2){
	assert(expr1);
	assert(expr2);	
	
	Expr * expr = newexpr(arithmeticexpr_e);
	expr->sym = istempexpr(expr1) ? expr1->sym :// Will reuse temp sym if available
			istempexpr(expr2) ? expr2->sym : newtemp();	
	
	switch (op){
		case ('+'): {
			printf("expr -> expr '+' expr\n");
	
			if ((expr1->type == numconst_e) && expr2->type == numconst_e){
				expr->numconst = expr1->numconst + expr2->numconst;
				expr->type = numconst_e;
			}
			else {
				if(expr1->type == programfunc_e ||
				   expr1->type == libraryfunc_e ||
				   expr1->type == boolexpr_e    ||
				   expr1->type == newtable_e    ||
				   expr1->type == boolconst_e   ||
				   expr1->type == stringconst_e ||
				   expr1->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				if(expr2->type == programfunc_e||
				   expr2->type == libraryfunc_e||
				   expr2->type == boolexpr_e   ||
				   expr2->type == newtable_e   ||
				   expr2->type == boolconst_e  ||
				   expr2->type == stringconst_e||
				   expr2->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				emit(add, expr1, expr2, expr, 0);
			}
			return (expr);
		}
		case ('-'): {
			printf("expr -> expr '-' expr\n");
	
			if ((expr1->type == numconst_e) && expr2->type == numconst_e){
				expr->numconst = expr1->numconst - expr2->numconst;
				expr->type = numconst_e;
			}
			else {
				if(expr1->type == programfunc_e ||
				   expr1->type == libraryfunc_e ||
				   expr1->type == boolexpr_e    ||
				   expr1->type == newtable_e    ||
				   expr1->type == boolconst_e   ||
				   expr1->type == stringconst_e ||
				   expr1->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				if(expr2->type == programfunc_e||
				   expr2->type == libraryfunc_e||
				   expr2->type == boolexpr_e   ||
				   expr2->type == newtable_e   ||
				   expr2->type == boolconst_e  ||
				   expr2->type == stringconst_e||
				   expr2->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				emit(sub, expr1, expr2, expr, 0);
			}
			return (expr);
		}
		case ('*'): {
			printf("expr -> expr '*' expr\n");
	
			if ((expr1->type == numconst_e) && expr2->type == numconst_e){
				expr->numconst = expr1->numconst * expr2->numconst;
				expr->type = numconst_e;
			}
			else {
				if(expr1->type == programfunc_e ||
				   expr1->type == libraryfunc_e ||
				   expr1->type == boolexpr_e    ||
				   expr1->type == newtable_e    ||
				   expr1->type == boolconst_e   ||
				   expr1->type == stringconst_e ||
				   expr1->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				if(expr2->type == programfunc_e||
				   expr2->type == libraryfunc_e||
				   expr2->type == boolexpr_e   ||
				   expr2->type == newtable_e   ||
				   expr2->type == boolconst_e  ||
				   expr2->type == stringconst_e||
				   expr2->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				emit(mul, expr1, expr2, expr, 0);
			}
			return (expr);
		}
		case ('/'): {
			printf("expr -> expr '/' expr\n");
	
			if ((expr1->type == numconst_e) && expr2->type == numconst_e){
				if (expr2->numconst == 0){ 
					printf("%d: #ERROR: Expression resolves to division by "
							"zero.\n", yylineno);
				}
				expr->numconst = expr1->numconst / expr2->numconst;
				expr->type = numconst_e;
			}
			else {
				if(expr1->type == programfunc_e ||
				   expr1->type == libraryfunc_e ||
				   expr1->type == boolexpr_e    ||
				   expr1->type == newtable_e    ||
				   expr1->type == boolconst_e   ||
				   expr1->type == stringconst_e ||
				   expr1->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				if(expr2->type == programfunc_e||
				   expr2->type == libraryfunc_e||
				   expr2->type == boolexpr_e   ||
				   expr2->type == newtable_e   ||
				   expr2->type == boolconst_e  ||
				   expr2->type == stringconst_e||
				   expr2->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				emit(divide, expr1, expr2, expr, 0);
			}
			return (expr);
		}
		case ('%'): {
			printf("expr -> expr '%%' expr\n");
			
			if ((expr1->type == numconst_e) && expr2->type == numconst_e){
				if (expr2->numconst == 0){ 
					printf("%d: #ERROR: Expression resolves to division by "
							"zero.\n", yylineno);
				}
				expr->numconst = fmod(expr1->numconst, expr2->numconst);
				expr->type = numconst_e;
			}
			else {
				if(expr1->type == programfunc_e ||
				   expr1->type == libraryfunc_e ||
				   expr1->type == boolexpr_e    ||
				   expr1->type == newtable_e    ||
				   expr1->type == boolconst_e   ||
				   expr1->type == stringconst_e ||
				   expr1->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				if(expr2->type == programfunc_e||
				   expr2->type == libraryfunc_e||
				   expr2->type == boolexpr_e   ||
				   expr2->type == newtable_e   ||
				   expr2->type == boolconst_e  ||
				   expr2->type == stringconst_e||
				   expr2->type == nil_e){
						printf("%d: #WARNING: Arithmetic operation with operant"
								" not of type 'number'.\n",yylineno);
				}
				emit(mod, expr1, expr2, expr, 0);
			}
			return (expr);
		}
	}
	assert(0); return NULL;
}

Expr* handle_op_op_lvalue (Expr* lvalue, char op){
	printf("term -> %c%clvalue\n",op, op);
	assert(lvalue);
	assert(lvalue->sym);

	if ((lvalue->sym->symbolType == FUNC) || (lvalue->sym->symbolType == LIB_FUNC)){
		printf("%d: #ERROR: Illegal expression '%c%c%s'. Function identifiers "
				"are const.\n", yylineno, op, op, lvalue->sym->name);
		// TODO signal error
		return NULL; //TODO was assert(0) here
	}
	else {
		Expr * term;
		switch (op){
			case '+':
				if (lvalue->type == tableitem_e){
					term = emit_iftableitem(lvalue);
					emit(add, term, newexpr_constnum(1), term, 0);
					emit(tablesetelem, lvalue, lvalue->index, term, 0);
					return term;
				}
				else {
					emit(add, lvalue, newexpr_constnum(1), lvalue, 0);
					term = newexpr(arithmeticexpr_e);
					term->sym = newtemp();
					emit(assign, term, NULL, lvalue, 0);
					return term;
				}
			case '-':
				if (lvalue->type == tableitem_e){
					term = emit_iftableitem(lvalue);
					emit(sub, term, newexpr_constnum(1), term, 0);
					emit(tablesetelem, lvalue, lvalue->index, term, 0);
					return term;
				}
				else {
					emit(sub, lvalue, newexpr_constnum(1), lvalue, 0);
					term = newexpr(arithmeticexpr_e);
					term->sym = newtemp();
					emit(assign, term, NULL, lvalue, 0);
					return term;
				}			
		}
	}
	assert(0);	// No man's land
	return NULL;
}

Expr* handle_lvalue_op_op (Expr* lvalue, char op){
	printf("term -> lvalue%c%c\n",op, op);
	assert(lvalue);
	assert(lvalue->sym);

	if ((lvalue->sym->symbolType == FUNC) || (lvalue->sym->symbolType == LIB_FUNC)){
		printf("%d: #ERROR: Illegal expression '%s%c%c'. Function identifiers "
				"are const.\n", yylineno, lvalue->sym->name, op, op);
		// TODO signal error
		return NULL; //TODO was assert(0) here
	}
	else {
		Expr* term, *value;
		switch (op){
			case '+':
				term = newexpr(var_e);
				term->sym = istempexpr(lvalue) ? lvalue->sym : newtemp();	// reusing temp sym
				if (lvalue->type == tableitem_e){
					value = emit_iftableitem(lvalue);
					emit(assign, value, NULL, term, 0);
					emit(add, value, newexpr_constnum(1), value, 0);
					emit(tablesetelem, lvalue, lvalue->index, value, 0);
					return term;
				}
				else{
					emit(assign, lvalue, NULL, term, 0);
					emit(add, lvalue, newexpr_constnum(1), lvalue, 0);
					return term;
				}
				
			case '-':				
				term = newexpr(var_e);
				term->sym = istempexpr(lvalue) ? lvalue->sym : newtemp();	// reusing temp sym
				if (lvalue->type == tableitem_e){
					value = emit_iftableitem(lvalue);
					emit(assign, value, NULL, term, 0);
					emit(sub, value, newexpr_constnum(1), value, 0);
					emit(tablesetelem, lvalue, lvalue->index, value, 0);
					return term;
				}
				else{
					emit(assign, lvalue, NULL, term, 0);
					emit(sub, lvalue, newexpr_constnum(1), lvalue, 0);
					return term;
				}
		}
	}
	assert(0);	// No man's land
	return NULL;
}

void checkuminus (Expr* e){
	assert(e);
	if (e->type == boolconst_e	||
	   e->type == stringconst_e	||
	   e->type == nil_e			||
	   e->type == newtable_e	||
	   e->type == programfunc_e	||
	   e->type == libraryfunc_e	||
	   e->type == boolexpr_e)
	   printf("%d: #ERROR: Illegal expr to unary '-'\n", yylineno);
}

Expr* handle_term_uminus_expr (Expr* e){
	printf("term -> -expr uminus\n");
	checkuminus(e);
	Expr* term = newexpr(arithmeticexpr_e);
	term->sym = istempexpr(e) ? e->sym : newtemp();
	emit(uminus, e, NULL, term, 0);
	return term;
}


#endif

