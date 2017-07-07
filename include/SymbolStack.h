#ifndef _SYMBOLSTACK_H_
#define _SYMBOLSTACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "SymbolTable.h"

typedef struct SymStackNode {
  struct Symbol* symbol;
  struct SymStackNode* next;
}SymStackNode;

typedef struct SymbolStack {
  struct SymStackNode* top;
  int count;
}SymbolStack;


/*
 * Creates a new SymStackNode structure for a Stack supporting Symbols.
 *
 * Returns a pointer to the newly created SymStackNode.
 */
SymStackNode* createSymbolStackNode();


/*
 * Creates a new Stack structure supporting Symbols.
 *
 * Returns a pointer to the newly created Symbol Stack.
 */
SymbolStack* createSymbolStack();


/* 
 * Pushes the Symbol provided into the top of the Symbol Stack provided.
 */
void pushSymbol (SymbolStack* myStack, struct Symbol* mySymbol);


/* 
 * Pops the top SymStackNode of the Symbol Stack provided.
 *
 * Returns a pointer to the Symbol the top SymStackNode linked to.
 * Returns NULL if popSymbol() fails.
 */
struct Symbol* popSymbol (SymbolStack* myStack);


/*
 * Checks if the provided Symbol Stack contains any nodes.
 *
 * Returns 0 if Symbol Stack provided is empty.
 * Returns a 1 if populated.
 */
int isEmptySymbolStack (SymbolStack* myStack);


/* 
 * Returns the count of Nodes the provided Stack contains.
 */
int getSize (SymbolStack* myStack);


/* 
 * Returns a pointer to the Symbol placed at the top of the Stack.
 */
struct Symbol* topSymbol (SymbolStack* myStack);


/*
 * Destroys the Symbol Stack provided and frees all alocated memory.
 */
void destroySymbolStack (SymbolStack* myStack);

#endif
