#ifndef _EXPRDBLLIST_H_
#define _EXPRDBLLIST_H_

#include <stdlib.h>
#include <assert.h>
#include "expressions.h"


typedef struct ExprDblNode {
  struct ExprDblNode * next;
  struct ExprDblNode * prev;
  struct Expr *        key;
  struct Expr *       value;
}ExprDblNode;

/* A struct designed to function as a double linked list of Expr pairs.
 * @size is the length of the list counted in number of Expr nodes
 * @head points to the first Token node in the list
 * @tail points to the last
 */
typedef struct ExprDblList {
  unsigned int size;
  ExprDblNode * head;
  ExprDblNode * tail;
} ExprDblList;

/* Returns new empty list. */
ExprDblList * createExprDblList (void);

/* Returns length of a list counted in number of ExprDblNodes. */
unsigned int getExprDblListLength (ExprDblList * elist);

/* Adds @expr1 and @expr2 to a ExprDblNode located at the head of @elist. */
void addExprDblListFront (ExprDblList * elist, struct Expr * key, struct Expr * value);

/* Prints out all the DblExpr's in the @elist from the oldest to the newest. */
void printExprDblList (ExprDblList * elist);

#endif  /* EXPRLIST_H */
