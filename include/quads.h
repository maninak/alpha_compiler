#ifndef _QUADS_H_
#define _QUADS_H_

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(Quad))
#define NEW_SIZE  (EXPAND_SIZE*sizeof(Quad)+CURR_SIZE)

extern int        currentScope;
extern unsigned   currQuad;        // The next empty slot in the array to input a quad
extern unsigned   total;           // The total space of the quads table

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ExprList.h"
#include "SymbolTable.h"
#include "IntStack.h"
#include "expressions.h"

typedef enum IOPCODE {
  assign,         add,            sub,
  mul,            divide,         mod,
  uminus,         if_eq,          if_noteq,
  if_lesseq,      if_greatereq,   if_less,
  if_greater,     call,           param,
  ret,            getretval,      funcstart,
  funcend,        tablecreate,    tablegetelem,
  tablesetelem,   jump,           emptyquad
}IOPCODE;

typedef struct Quad {
  enum   IOPCODE  op;             // The operation that the quad is to perform
  struct Expr *   arg1;           // Argument 1 for an operation
  struct Expr *   arg2;           // Argument 2 for an operation
  struct Expr *   result;         // Where the operation's result is to be stored
  unsigned        taddress;
  unsigned        label;          // The quad to which a jump op will be performed
  unsigned        line;           // The line of input code to which the quad corresponds
}Quad;

extern Quad *     quads;          // The data structure containing all the quads emitted

unsigned          nextquadlabel   ();
void              emit            (IOPCODE op, struct Expr* arg1,
                                      struct Expr* arg2, struct Expr* result,
                                      unsigned label
                                  );
struct Expr *     emit_iftableitem(struct Expr * e);
void              expand          ();
struct Expr *     member_item     (struct Expr *, char *);
//struct Expr *         make_call  (struct Expr *, struct ExprList *);
IntStack *        makelist        (int i);
void              backpatch       (IntStack * list, unsigned label);
void              patchlabel      (unsigned quadNo, int label);
int               print_const     (struct Expr * e);
char*             OPtoString      (IOPCODE op);
void              printQuads      ();

#endif
