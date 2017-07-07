#ifndef _INTSTACK_H_
#define _INTSTACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct IntStackNode {
	int value;
	struct IntStackNode* next;
}IntStackNode;

typedef struct IntStack {
	struct IntStackNode* top;
	unsigned count;
}IntStack;


/*
 * Creates a new IntStackNode structure for a Stack supporting integers.
 *
 * Returns a pointer to the newly created IntStackNode.
 */
IntStackNode * createIntStackNode();


/*
 * Creates a new Stack structure supporting integers.
 *
 * Returns a pointer to the newly created IntStack.
 */
IntStack * createIntStack();


/* 
 * Pushes the integer provided into the top of the IntStack provided.
 */
void pushInt (IntStack *, int);


/* 
 * Pops the top IntStackNode of the IntStack provided.
 *
 * Returns the value of the top SymStackNode that just got popped.
 * Returns -1 if popSymbol() fails.
 */
int popInt (IntStack *);


/*
 * Returns the value of the top SymStackNode of the Stack provided.
 */
int topInt (IntStack *);


/*
 * Checks if the provided IntStack contains any nodes.
 *
 * Returns 0 if IntStack provided is empty.
 * Returns a 1 if populated.
 */
int isEmptyIntStack (IntStack *);


/* 
 * Returns the count of Nodes the provided Stack contains.
 */
int getIntStackSize (IntStack *);

/*
 * Returns a Stack with the merged values of the two stacks provided
 * POSTCONDITION: allows multiple instances of the save integer value in the
 * returned stack. Frees memory as needed.
 */
IntStack * mergeIntStacks (IntStack *, IntStack *);

/*
 * Destroys the IntStack provided and frees all allocated memory.
 */
void destroyIntStack (IntStack *);

/*
 * Prints the data of the IntStack provided
 */
void printIntStack (IntStack *);


#endif
