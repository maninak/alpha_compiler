/* 
 * File:   const_tables.h
 *
 * Created on June 3, 2014, 1:06 PM
 */

#ifndef _CONST_TABLES_H_
#define	_CONST_TABLES_H_

#include "generator.h"
#include "instructions.h"
#include "vmarguments.h"


#define EXPAND_SIZE 1024
#define CURR_SIZE_STR 	(max_STR*sizeof(StrContainer))
#define NEW_SIZE_STR	(EXPAND_SIZE*sizeof(StrContainer)+CURR_SIZE_STR)

#define CURR_SIZE_NUM 	(max_NUM*sizeof(NumberContainer))
#define NEW_SIZE_NUM	(EXPAND_SIZE*sizeof(NumberContainer)+CURR_SIZE_NUM)


#define CURR_SIZE_LIB 	(max_LIB*sizeof(LibfuncContainer))
#define NEW_SIZE_LIB	(EXPAND_SIZE*sizeof(LibfuncContainer)+CURR_SIZE_LIB)

#define CURR_SIZE_USR 	(max_USR*sizeof(UserfuncContainer))
#define NEW_SIZE_USR	(EXPAND_SIZE*sizeof(UserfuncContainer)+CURR_SIZE_USR)


typedef struct StrContainer{
    char* string;			//The value of string
}StrContainer;

typedef struct NumberContainer{
    double number;			//The value of number
}NumberContainer;

typedef struct LibfuncContainer {    
    char *	 libfunc_name;	//The name of the library Function
}LibfuncContainer;

typedef struct UserfuncContainer{
	unsigned taddress;		//The number of the first produced final-Instruction
    unsigned locals;		//The number of locals
    char *	 name;			//The name of the user function    
}UserfuncContainer;


extern StrContainer *		string_table; // The table holding strings
extern unsigned max_STR;						// The maximum capacity of the array
extern unsigned curr_STR;						// The next empty slot in the array to input a quad

extern NumberContainer *	number_table; // The table holding numbers
extern unsigned max_NUM;						// The maximum capacity of the array
extern unsigned curr_NUM;						// The next empty slot in the array to input a quad

extern LibfuncContainer *	libfuncs_table;	// The table holding library functions
extern unsigned max_LIB;						// The maximum capacity of the array
extern unsigned curr_LIB;						// The next empty slot in the array to input a quad

extern UserfuncContainer * usrfuncs_table;	// The table holding userFunctions
extern unsigned max_USR;						// The maximum capacity of the array
extern unsigned curr_USR;						// The next empty slot in the array to input a quad


/* Adds a new string in the string table.
 * 
 * Returns the index of the imported string in the array (In the val field of the vmarg ussualy)
 */
unsigned    add_new_STR(char *);

/* Expands the size of the table when it's full */
void        expand_STR();

/* Adds a new number in the numbers table.
 * 
 * Returns the index of the imported number in the array (In the val field of the vmarg ussualy)
 */
unsigned    add_new_NUM(double);

/* Expands the size of the table when it's full */
void        expand_NUM();

/* Adds the lib function's name in the lib function table.
 * 
 * Returns the index of the imported "lib function"(just the name) in the array (In the val field of the vmarg ussualy)
 */
unsigned    add_new_LIB(char *);

/* Expands the size of the table when it's full */
void        expand_LIB();

/* Adds a user function(taddress,number of local arguments,name of the function)  in the user function table.
 * 
 * Returns the index of the imported "user function" in the array (In the val field of the vmarg ussualy)
 */
unsigned    add_new_USR(unsigned,unsigned,char *);

/* Expands the size of the table when it's full */
void        expand_USR();

/* Prints all the table's contents */
void		printConstTables();

#endif	/* CONST_TABLES_H */
