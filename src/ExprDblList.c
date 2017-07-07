#ifndef __EXPRLIST_C__
#define	__EXPRLIST_C__

#include "../include/ExprDblList.h"

ExprDblList * createExprDblList(void){
	ExprDblList * elist = (ExprDblList *) malloc(sizeof(ExprDblList));
	elist->size = 0;
	elist->head = NULL;
	elist->tail = NULL;
	return elist;
}

unsigned int getExprDblListLength(ExprDblList * elist){
	assert(elist);
	return elist->size;
}


void addExprDblListFront(ExprDblList * elist, Expr * key, Expr * value){
	assert(elist);
	
	ExprDblNode * newNode = malloc(sizeof(ExprDblNode));
	newNode->key   = key;
	newNode->value = value;

	// Case elist empty
	if (elist->head == NULL){
		newNode->next = NULL;
		newNode->prev = NULL;
		elist->head = newNode;
		elist->tail = newNode;
	}
	else { // Case elist populated
		newNode->prev = elist->head;
		elist->head->next = newNode;
		newNode->next = NULL;
		elist->head = newNode;
	}

	elist->size++;
}

void printExprDblList (ExprDblList * elist){
	assert(elist);
	
	ExprDblNode * cur = elist->tail;
	while (cur->next != NULL){
		// print
		cur = cur->next;
	}
}

#endif	/* EXPRLIST_C */

