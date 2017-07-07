#ifndef __EXPRLIST_C__
#define	__EXPRLIST_C__

#include "../include/ExprList.h"

ExprList * createExprList(void){
	ExprList * elist = (ExprList *) malloc(sizeof(ExprList));
	elist->size = 0;
	elist->head = NULL;
	elist->tail = NULL;
	return elist;
}

unsigned int getExprListLength(ExprList * elist){
	assert(elist);
	return elist->size;
}


void addExprListFront(ExprList * elist, Expr * expr){
	assert(elist);
	
	ExprNode * newNode = malloc(sizeof(ExprNode));
	newNode->expr = expr;

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

void printExprList (ExprList * elist){
	assert(elist);
	
	ExprNode * cur = elist->tail;
	while (cur->next != NULL){
		// print
		cur = cur->next;
	}
}

#endif	/* EXPRLIST_C */

