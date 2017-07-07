#ifndef _EXPRESSIONS_C_
#define _EXPRESSIONS_C_

#include "../include/expressions.h"

Expr* newexpr (EXPR_TYPE t){
	Expr* e = (Expr*) malloc (sizeof(Expr));
	memset(e, 0, sizeof(Expr));
	e->breaklist	= createIntStack(); //TODO should be created only upon need
	e->contlist	= createIntStack();
	e->truelist	= createIntStack();
	e->falselist	= createIntStack();
	e->elist	= createExprList();
	e->dblelist	= createExprDblList();
	e->type		= t;
	return e;
}

Expr* newexpr_conststring (char* s){
	Expr* e = newexpr(stringconst_e);
	e->strconst = strdup(s);
	return e;
}


Expr* newexpr_constbool (int boolconst){
	Expr* e = newexpr(boolconst_e);
	if(boolconst == 0)
		e->boolconst = 0;
	else
		e->boolconst = 1;
	return e;
}

Expr* newexpr_constnum (double Valnumber){
	Expr* e = newexpr(numconst_e);
	e->numconst = Valnumber;
	return e;
}

Expr* lvalue_expr (struct Symbol* mySymbol){
	assert(mySymbol);

	Expr * e = newexpr(nil_e);
	e->next	= (Expr*) 0;
	e->sym	= mySymbol;

	switch (mySymbol->symbolType){
		case (VAR)	:		e->type = var_e; 			break;
		case (ARG)	:		e->type = var_e; 			break;
		case (FUNC)	:		e->type = programfunc_e; 	break;
		case (LIB_FUNC)	:	e->type = libraryfunc_e;	break;
		default: assert(0);
	}
	return e;
}

#endif
