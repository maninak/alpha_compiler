#ifndef _MANAGE_H_
#define _MANAGE_H_

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "SymbolTable.h"
#include "SymbolStack.h"
#include "IntStack.h"
#include "handler.h"
#include "expressions.h"
#include "offsets.h"
#include "quads.h"
#include "ExprList.h"
#include "ExprDblList.h"


extern int            yylineno;
extern char *         yytext;
extern FILE *         yyin;
extern int            currentScope;


struct Symbol      *  tempSymbol;       // A symbol pointer for general use
struct SymbolTable *  mySymTab;         // The main Symbol Table structure
struct SymbolStack *  curFuncStack;     // Current function being declared is top
struct IntStack    *  scopeOffsetStack; // Current offset of local vars is top


void            initManager                                       ();

//program
void            manage_stmts                                      ();

//stmts
void            manage_stmts_stmt                                 ();
void            manage_stmts_empty                                ();

//stmt
void            manage_stmt_expr                                  (struct Expr *);
void            manage_stmt_if                                    ();
void            manage_stmt_while                                 ();
void            manage_stmt_forstmt                               ();
void            manage_stmt_returnstmt                            ();
void            manage_stmt_brk                                   ();
void            manage_stmt_cntnue                                ();
void            manage_stmt_block                                 ();
void            manage_stmt_funcdef                               ();
void            manage_stmt_UNRECOGNIZED                          ();
void            manage_stmt_error                                 ();
void            manage_stmt_semicolumn                            ();

//expr
struct Expr *   manage_expr_assignexpr                            (struct Expr *);
void            manage_expr_expr_plus_expr                        ();
void            manage_expr_expr_minus_expr                       ();
void            manage_expr_expr_star_expr                        ();
void            manage_expr_expr_div_expr                         ();
void            manage_expr_expr_mod_expr                         ();
void            manage_expr_expr_greater_expr                     ();
void            manage_expr_expr_GREATER_EQ_expr                  ();
void            manage_expr_expr_less_expr                        ();
void            manage_expr_expr_LESS_EQ_expr                     ();
void            manage_expr_expr_EQ_expr                          ();
void            manage_expr_expr_NOT_EQ_expr                      ();
void            manage_expr_expr_AND_expr                         ();
void            manage_expr_expr_OR_expr                          ();
struct Expr *   manage_expr_term                                  (struct Expr *);

//term
struct Expr *   manage_term_expr_parenthesis                      (struct Expr *);
void            manage_term_UMINUS_expr                           ();
void            manage_term_NOT_expr                              ();
void            manage_term_PLUS_PLUS_lvalue                      (struct Expr *);
void            manage_term_lvalue_PLUS_PLUS                      (struct Expr *);
void            manage_term_MINUS_MINUS_lvalue                    (struct Expr *);
void            manage_term_lvalue_MINUS_MINUS                    (struct Expr *);
struct Expr *   manage_term_primary                               (struct Expr *);

//assignexpr
struct Expr *   manage_assignexpr_lvalue_assign_expr              (struct Expr *, struct Expr *);

//primary
struct Expr *   manage_primary_lvalue                             (struct Expr *);
struct Expr *   manage_primary_call                               (struct Expr *);
struct Expr *   manage_primary_tablemake                          (struct Expr *);
struct Expr *   manage_primary_par_funcdef                        (struct Symbol *);
struct Expr *   manage_primary_const                              (struct Expr *);

//lvalue
struct Expr *   manage_lvalue_ID                                  (char *);
struct Expr *   manage_lvalue_LOCAL_ID                            (char *);
struct Expr *   manage_lvalue_DBLCOLON_ID                         (char *);
void            manage_lvalue_tableitem                           ();

//tableitem
struct Expr *   manage_tableitem_lvalue_dot_ID                    (struct Expr *, char *);
struct Expr *   manage_tableitem_lvalue_brackets_expr             (struct Expr *, struct Expr *);
void            manage_tableitem_call_dot_ID                      ();
void            manage_tableitem_call_brackets_expr               ();

//call
//struct Expr *  manage_call_call_par_elist    (struct Expr *, struct ExprList *);
struct Expr *   manage_call_lvalue_callsuffix                     (struct Expr *, struct Expr *);
struct Expr *   manage_call_par_funcdef_normcall                  (struct Symbol *, struct Expr *);

//callsuffix
struct Expr *   manage_callsuffix_normcall                        (struct Expr *);
struct Expr *   manage_callsuffix_methodcall                      (struct Expr *);

//normcall
//struct Expr *   manage_normcall_par_elist    (struct ExprList *);

//methodcall
//struct Expr *  manage_methodcall_DBL_DOT_ID_par_elist (char * id, struct ExprList *);

//elist
void            manage_elist_expr_exprs                           ();
void            manage_elist_empty                                ();

//exprs
void            manage_exprs_comma_expr_exprs                     ();
void            manage_exprs_empty                                ();

//tablemake
//struct Expr *  manage_tablemake_squarebr_elist    (struct ExprList *);
//struct Expr *  manage_tablemake_squarebr_indexed  (struct ExprDblList *);

//indexed
void            manage_indexed_indexedelem_indexedelems           ();

//indexedelems
void            manage_indexedelems_comma_indexedelem_indexedelems();
void            manage_indexedelems_empty                         ();

//indexedelem
void            manage_indexedelem_brackets_expr_column_expr      ();

//block
void            manage_block_brackets_stmts                       ();

//funcdef
struct Symbol * manage_funcdef_funcprefix_funcargs_funcbody       (struct Symbol *, int);
struct Symbol * manage_funcprefix_FUNCTION_funcname               (char *);
char *          manage_funcname_ID                                (char *);
char *          manage_funcname_empty                             ();
void            manage_funcargs_PAR_idlist_PAR                    ();
void            manage_funcbody_block                             (int *);
struct Symbol * newFunctionSymbol                                 (char *);

//const
struct Expr *   manage_const_NUMBER                               (double);
struct Expr *   manage_const_STR                                  (char *);
struct Expr *   manage_const_NIL                                  ();
struct Expr *   manage_const_TRUE                                 ();
struct Expr *   manage_const_FALSE                                ();

//idlist
void            manage_idlist_ID_ids                              (char *);
void            manage_idlist_empty                               ();

//ids
void            manage_ids_comma_ID_ids                           (char *);
void            manage_ids_empty                                  ();

//if
void            manage_if_ifprefix_stmt                           (int);
void            if_ifprefix_stmt_elseprefix_stmt                  (int, int);

//ifprefix
int             manage_ifprefix_IF_par_expr                       (struct Expr * expr);

//elseprefix
int             manage_elseprefix_ELSE ();

//while
void            manage_while_whilestart_whilecond_stmt            (int, int, struct Expr *);
int             manage_whilestart_WHILE                           ();
int             manage_whilecond_par_expr                         (struct Expr *);

//forstmt
void            manage_forstmt_FOR                                ();

//returnstmt
void            manage_returnstmt_RETURN_expr_semicolon           (struct Expr *);
void            manage_returnstmt_RETURN_semicolon                ();

//break
struct Expr *   manage_break_BREAK                                ();

//continue
struct Expr *   manage_continue_CONTINUE                          ();

// TEMPORARY VARIABLES
void            resetTempVarCount                                 ();

/*
 * Returns a Symbol pointer to a clean temporary variable (hidden or new).
 */
struct Symbol * newtemp                                           ();

/*
 * Checks if the symbol in the Expression struct provided is a temporary
 * variable of the compiler.
 *
 * Returns 1 if so, 0 if it is not a temporary variable.
 */
int             istempexpr                                        (struct Expr *e);

# endif
