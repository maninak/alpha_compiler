#ifndef _HANDLER_C_
#define _HANDLER_C_

#include <string.h>
#include <math.h>
#include "expressions.h"
#include "IntStack.h"
#include "SymbolTable.h"
#include "quads.h"
#include "offsets.h"

extern int yylineno;

struct Expr * handle_expr_gr_expr     (struct Expr *, struct Expr *);
struct Expr * handle_expr_gr_eq_expr  (struct Expr *, struct Expr *);
struct Expr * handle_expr_ls_expr     (struct Expr *, struct Expr *);
struct Expr * handle_expr_ls_eq_expr  (struct Expr *, struct Expr *);
struct Expr * handle_expr_eq_expr     (struct Expr *, struct Expr *);
struct Expr * handle_expr_not_eq_expr (struct Expr *, struct Expr *);
void          trueTest                (struct Expr *);
int           handle_boolean_M        ();
struct Expr * handle_expr_and_expr    (struct Expr *, int, struct Expr *);
struct Expr * handle_expr_or_expr     (struct Expr *, int, struct Expr *);
struct Expr * handle_term_not_expr    (struct Expr *);
struct Expr * handle_expr_op_expr     (struct Expr *, char, struct Expr *);
struct Expr * handle_op_op_lvalue     (struct Expr *, char op);
struct Expr * handle_lvalue_op_op     (struct Expr *, char op);
void           checkuminus            (struct Expr *);
struct Expr * handle_term_uminus_expr (struct Expr *);

#endif
