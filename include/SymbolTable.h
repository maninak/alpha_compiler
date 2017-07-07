#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#define PRIME           401
#define MAX_SCOPE_DEPTH 100
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "SymbolStack.h"
#include "manage.h"
#include "IntStack.h"

// extern curFuncStack; //TODO delete if not needed
extern int            yylineno;

typedef enum          SYMBOL_TYPE  { VAR, FUNC, ARG, LIB_FUNC  } SYMBOL_TYPE;
typedef enum          SCOPE_SPACE  { _PROGRAM, _FORMAL, _LOCAL } SCOPE_TYPE;

typedef struct        SymbolTable {
  unsigned int        symbolCount;    // The count of symbols stored in the table (needed for rehash)
  unsigned int        size;           // The size of the table in buckets (needed for rehash)
  struct Symbol**     hashTable;
}SymbolTable;


typedef struct Symbol {
  char *              name;
  int                 isActive;
  enum SYMBOL_TYPE    symbolType;
  enum SCOPE_SPACE    scopeSpace;
  unsigned int        declInLine;     // The line in which a symbol is declared
  unsigned short      declInScope;    // The scope depth in which a symbol is declared
  unsigned            iadress;        // used in manage_funcprefix_FUNCTION_funcname() (?) //TODO delete if not needed
  unsigned            taddress;       //Used in the final code phase to pair intermediate with the first produced final code instruction
  unsigned            offset;         // Used only by VAR and FORMAL Symbols
  unsigned            totalLocals;    // Used only by FUNC and LIB_FUNC Symbols
  struct Symbol *     nextSymbol;     // Links to the next Symbol in the Symbol Table's bucket list
  struct Symbol *     nextInScope;    // Links to the next Symbol that was declared in the same block
  struct Symbol *     declInFunc;     // Links to a function Symbol in which it was declared (if applicable)
  struct Symbol *     funcFormals;
  IntStack *          returnList;
}Symbol;

extern int                  currentScope;
extern SymbolTable *        mySymTab;
extern struct SymbolStack * curFuncStack;

/*
 * An array of pointers to Symbols. Each one points to a usable Symbol with 
 * currentScope that equals that of the pointer's index.
 */
Symbol* scopeLinkArray[MAX_SCOPE_DEPTH];


/*
 * Calculates an integer value based on the string parameter provided.
 *
 * Returns an integer value between 0 and PRIME.
 */
int hashFunction (char* s);


/*
 * Creates a new Symbol node and initializes values according to 
 * parameters provided.
 *
 * Returns a pointer to the Symbol created.
 */
Symbol* createSymbol ( char* name, SYMBOL_TYPE);


/*
 * Creates a new lib function Symbol node and initializes values according to
 * parameters provided.
 *
 * Returns a pointer to the Symbol created.
 */
Symbol* createLibSymbol ( char* name, SYMBOL_TYPE);


/* 
 * Inserts the Symbol provided to the Symbol Table.
 */
void insert(Symbol* mySymbol);


/*
 * Inserts a formal argument provided via parameter mySymbol to the 
 *  currentFunc's funcFormals list.
 *
 * PRECONDITION: Parameter mySymbol is _FORMAL (or ARG not sure TODO check)
 * POSTCONDITION: After all formals are inserted in currentFunc's funcFormals
 * list,they will always be accessible in the opposite order they were declared.
 */
void insertFormal(Symbol*);


/*
 * Creates a Symbol Table structure.
 *
 * Returns a pointer to the Symbol Table created.
 */
SymbolTable* createSymbolTable ();


/*
 * Initializes the Symbol Table with all reserved Symbols of the language.
 */
void initSymbolTable();


/*
 * Hides all Symbols in the Symbol Table in depth as deep as stated
 * via the global var currentScope.
 */
void hide ();


/*
 * Looks up the Hash Table for the Symbol that has the same name
 * as the name provided via the parameter, which is active and is closest
 * to the current scope depth.
 *
 * RETURNS the Symbol declared in scope closest to the currentScope if found,
 * or NULL if not.
 */
Symbol* lookup(char* name);


/*
 * Looks up the Hash Table for the Symbol that has the same name
 * as the name provided via the parameter, which is active and is
 * specifically in the scope depth provided via parameter.
 */
Symbol* lookupInScope(char* name, int depth);


int isLibSymbol(char* name);


/*
 * Prints all the Symbols and their attributes in the symbol list 
 * provided as a parameter.
 */
void printSymbolList (Symbol* mySymbol);

/*
 * Inserts the provided Symbol into the specified bucket of the Symbol Table
 * provided as parameter.
 */
void insertSymbolInBucket (  Symbol*, unsigned int, SymbolTable* sortedSymTab);


/*
 * Creates a new Symbol Table containing all the Symbols of the
 * main Symbol Table, each inserted in the exact bucket of its respective line
 * of declaration. E.g. symbol declared in line 5 is inserted in bucket 5, etc.
 *
 * Returns the new sorted by declaration line Symbol Table.
 *
 * POSTCONDITION: former bucket chains of global mySymTab are reordered (broken)
 */
SymbolTable* createSortedSymbolTable ();


/*
 * Prints all the Symbols in the Symbol Table and their attributes.
 */
void printSymbolTable ();

# endif

