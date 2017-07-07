#ifndef _INTSTACK_C_
#define _INTSTACK_C_
#include "../include/IntStack.h"

IntStackNode* createIntStackNode(){
	IntStackNode* newNode = (IntStackNode*) malloc (sizeof(IntStackNode));
	newNode->value 	= 0;
	newNode->next 	= NULL;
	return newNode;
}

IntStack * createIntStack() {
	IntStack* newStack = (IntStack *) malloc (sizeof(IntStack));
	newStack->count = 0;
	newStack->top 	= NULL;
	return newStack;
}

void pushInt (IntStack * myStack, int myValue){
	assert(myStack);
	
	IntStackNode * newNode = createIntStackNode();
	newNode->value 	= myValue;
	newNode->next 	= myStack->top;
	myStack->top 	= newNode;
	myStack->count++;
}

int popInt (IntStack * myStack){
	assert(myStack);
	
	if (myStack->count == 0){		
		assert(0);	// No man's land
		return -1;
	}
	else {
		int value = myStack->top->value;
		IntStackNode * tmpTop = myStack->top;
		myStack->top = myStack->top->next;
		free(tmpTop);
		myStack->count--;
		return value;
	}
}

int topInt (IntStack * myStack){
	assert(myStack);
	assert(myStack->top);

	return myStack->top->value;
}

int isEmptyIntStack (IntStack * myStack){
	assert(myStack);
	
	if (myStack->count > 0)		{ return 0; }
	else 						{ return 1; }
}

int getIntStackSize (IntStack * myStack){
	assert(myStack);
	
	return myStack->count;
}

IntStack * mergeIntStacks (IntStack * s1, IntStack * s2){
	assert(s1);
	assert(s2);

	while (!isEmptyIntStack(s2)){ //TODO optimize to for i < x = stack size
		pushInt(s1, popInt(s2));
	}
	destroyIntStack(s2);
	return s1;
}

void destroyIntStack (IntStack * myStack){
	assert(myStack);
	
	while (!isEmptyIntStack(myStack)){
		popInt(myStack);
	}
	free(myStack);
}

void printIntStack (IntStack * myStack){
	assert(myStack);
	
	IntStackNode * curNode = myStack->top;
	printf("[ ");
	while (curNode != NULL){
		printf("%d ", curNode->value);
		curNode = curNode->next;
	}
	printf("]\n");	
}

#endif
