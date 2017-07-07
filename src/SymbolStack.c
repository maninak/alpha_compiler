#ifndef _SYMBOLSTACK_C_
#define _SYMBOLSTACK_C_
#include "../include/SymbolStack.h"


SymStackNode* createSymbolStackNode(){
	SymStackNode* newNode = (SymStackNode*) malloc (sizeof(SymStackNode));
	newNode->symbol = NULL;
	newNode->next = NULL;
	return newNode;
}

SymbolStack* createSymbolStack() {
	SymbolStack* newStack = (SymbolStack*) malloc (sizeof(SymbolStack));
	newStack->count = 0;
	newStack->top = createSymbolStackNode();
	return newStack;
}

void pushSymbol (SymbolStack* myStack, struct Symbol* mySymbol){
	assert(myStack);//TODO Maybe delete 
	assert(mySymbol);
	
	SymStackNode* newNode = createSymbolStackNode();
	newNode->symbol = mySymbol;
	newNode->next = myStack->top;
	myStack->top = newNode;
	myStack->count++;
}

struct Symbol* popSymbol (SymbolStack* myStack){
	assert(myStack);
	
	if (myStack->count == 0){		
		/*printf ("# Stack popSymbol() call error. ");
		printf ("Stack was already empty upon popSymbol() call.\n");*/
		return NULL;
	}
	else {
		SymStackNode* tmpTop = myStack->top;
		struct Symbol* tmpSymbol = tmpTop->symbol;
		myStack->top = myStack->top->next;
		free(tmpTop);
		myStack->count--;
		return tmpSymbol;
	}
}

int isEmptySymbolStack (SymbolStack* myStack){
	assert(myStack);
	
	if (myStack->count) { return 0; }
	else { return 1; }
}

int getSize (SymbolStack* myStack){
	assert(myStack);
	
	return myStack->count;
}

struct Symbol* topSymbol (SymbolStack* myStack){
	assert(myStack);
	return myStack->top->symbol;
}

void destroySymbolStack (SymbolStack* myStack){
	assert(myStack);
	
	myStack->count++; // Increment count for dummy Node
	while (!isEmptySymbolStack(myStack)){
		popSymbol(myStack);
	}
	free(myStack);
}
#endif
