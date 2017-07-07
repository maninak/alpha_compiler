#ifndef _EXPRESSIONS_H_
#define _EXPRESSIONS_H_

#include <stdlib.h>
#include <assert.h>
#include "IntStack.h"
#include "SymbolTable.h"
#include "ExprList.h"

typedef enum EXPR_TYPE {
  var_e,          tableitem_e,            programfunc_e,
  libraryfunc_e,  arithmeticexpr_e,       boolexpr_e,
  assignexpr_e,   newtable_e,             numconst_e,
  boolconst_e,    stringconst_e,          nil_e,
  break_e,        continue_e
}EXPR_TYPE;

typedef struct Expr {
  EXPR_TYPE             type;
  struct Symbol *       sym;
  struct Expr *         index;
  double                numconst;
  char *                strconst;
  unsigned int          boolconst;
  struct Expr *         next;
  struct Expr *         previous;
  IntStack *            breaklist;
  IntStack *            contlist;
  IntStack *            truelist;
  IntStack *            falselist;
  int                   method;
  char *                name;
  struct ExprList *     elist;
  struct ExprDblList *  dblelist;
}Expr;

Expr* newexpr               (EXPR_TYPE t);
Expr* newexpr_conststring   (char* s);
Expr* newexpr_constbool     (int boolconst);
Expr* newexpr_constnum      (double Valnumber);
Expr* lvalue_expr           (struct Symbol* mySymbol);

#endif
