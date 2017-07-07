#ifndef _EXPRLIST_H_
#define _EXPRLIST_H_

#include <stdlib.h>
#include <assert.h>
#include "expressions.h"


typedef struct ExprNode {
  struct ExprNode * next;
  struct ExprNode * prev;
  struct Expr *     expr;
}ExprNode;

/* A struct designed to function as a double linked list of Expr's.
 * @size is the length of the list counted in number of Expr nodes
 * @head points to the first Token node in the list
 * @tail points to the last
 */
typedef struct ExprList {
  unsigned int  size;
  ExprNode *    head;
  ExprNode *    tail;
} ExprList;

/* Returns new empty list. */
ExprList * createExprList (void);

/* Returns length of a list counted in number of Token nodes. */
unsigned int getExprListLength (ExprList * elist);

/* Adds the @expr to an ExprNode located at the head of @elist. */
void addExprListFront (ExprList * elist, struct Expr * expr);

/* Prints out all the Expr's in the @elist from the oldest to the newest. */
void printExprList (ExprList * elist);

#endif  /* EXPRLIST_H */
