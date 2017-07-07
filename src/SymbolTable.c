#ifndef SYMBOLTABLE_C
#define SYMBOLTABLE_C

#include "../include/SymbolTable.h"


int hashFunction (char* s){   
  char* p;
  unsigned h=0, g=0;

  for (p=s; *p != '\0'; p++){
    h = (h<<4) + (*p);
    if (g == (h&0xf0000000)){
      h = h ^ (g >> 24);
      h = h ^ g;
    }
  }
  return h % PRIME;
}

Symbol* createSymbol (char* name, SYMBOL_TYPE symbolType) {
  Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
  newSymbol->name     = strdup(name);
  newSymbol->isActive   = 1;
  newSymbol->symbolType   = symbolType;
  newSymbol->scopeSpace   = currscopespace();
  newSymbol->declInLine   = yylineno;
  newSymbol->declInScope   = currentScope;
  newSymbol->offset    = currscopeoffset();
  newSymbol->totalLocals   = 0;
  newSymbol->nextSymbol   = NULL;
  newSymbol->nextInScope   = NULL;
  newSymbol->funcFormals   = NULL;
  newSymbol->declInFunc   = topSymbol(curFuncStack);
  newSymbol->funcFormals   = NULL;
        newSymbol->returnList   = createIntStack();
  incurrscopeoffset();
  return newSymbol;
}

Symbol* createLibSymbol (char* name, SYMBOL_TYPE symbolType) { // TODO delete after test with createSymbol and not needed
  Symbol* newSymbol = (Symbol*) malloc(sizeof(Symbol));
  newSymbol->name     = strdup(name);
  newSymbol->isActive   = 1;
  newSymbol->symbolType   = symbolType;
  newSymbol->scopeSpace   = _PROGRAM;
  newSymbol->declInLine   = 0;
  newSymbol->declInScope   = 0;
  newSymbol->offset    = 0;
  newSymbol->totalLocals   = 0;
  newSymbol->nextSymbol   = NULL;
  newSymbol->nextInScope   = NULL;
  newSymbol->funcFormals   = NULL;
  newSymbol->declInFunc   = NULL;
  newSymbol->funcFormals   = NULL;
  incurrscopeoffset();
  return newSymbol;
}

void insert(Symbol* mySymbol){
  assert(mySymbol != NULL);
  int index = hashFunction(mySymbol->name);  // Calculates hash value
  mySymbol->nextSymbol = mySymTab->hashTable[index];
  mySymTab->hashTable[index] = mySymbol; // Inserts Symbol in Hash Table
  if (scopeLinkArray[mySymbol->declInScope] == NULL){
    scopeLinkArray[mySymbol->declInScope] = mySymbol;
  }    // If it's the first active symbol declared in that scope depth,
    // it is linked with the scopeLinkArray.
  else {
    mySymbol->nextInScope = scopeLinkArray[mySymbol->declInScope];
    scopeLinkArray[mySymbol->declInScope] = mySymbol;
  }   // If it's NOT the first active symbol declared in that scope depth,
    // it is placed in the first position of the declInScope list.
  mySymTab->symbolCount++;
}

void insertFormal(Symbol * mySymbol){
  assert(mySymbol);
  assert(mySymbol->scopeSpace == _FORMAL); // TODO validate
  assert(topSymbol(curFuncStack) != NULL);

  if (topSymbol(curFuncStack)->funcFormals == NULL){// if no more formals declared in func
    topSymbol(curFuncStack)->funcFormals = mySymbol;
  }
  else{
    mySymbol->funcFormals = topSymbol(curFuncStack)->funcFormals;
    topSymbol(curFuncStack)->funcFormals = mySymbol;
  }
}

SymbolTable* createSymbolTable (){
  // Create the Symbol Table struct
  SymbolTable* newSymTab = (SymbolTable*) malloc (sizeof(SymbolTable));
  // Allocate memory for each bucket
  newSymTab->hashTable = (Symbol**) malloc(sizeof(Symbol *) * PRIME);
  newSymTab->symbolCount = 0;
  newSymTab->size = PRIME;
  int i;
  for (i=0; i<PRIME; i++){
    newSymTab->hashTable[i] = NULL; // Initialize each pointer to NULL
  }
  return newSymTab;
}

void initSymbolTable(){
  // Insert the language-specific reserved Symbols
  insert(createLibSymbol("print",               LIB_FUNC));
  insert(createLibSymbol("input",               LIB_FUNC));
  insert(createLibSymbol("objectmemberkeys",    LIB_FUNC));
  insert(createLibSymbol("objecttotalmembers",  LIB_FUNC));
  insert(createLibSymbol("objectcopy",          LIB_FUNC));
  insert(createLibSymbol("totalarguments",      LIB_FUNC));
  insert(createLibSymbol("argument",            LIB_FUNC));
  insert(createLibSymbol("typeof",              LIB_FUNC));
  insert(createLibSymbol("strtonum",            LIB_FUNC));
  insert(createLibSymbol("sqrt",                LIB_FUNC));
  insert(createLibSymbol("cos",                 LIB_FUNC));
  insert(createLibSymbol("sin",                 LIB_FUNC));
}

void hide (){
  Symbol* mySymbol = scopeLinkArray[currentScope];
  while (mySymbol != NULL){
    mySymbol->isActive = 0;
    mySymbol = mySymbol->nextInScope;
  }
  scopeLinkArray[currentScope] = NULL;
}

Symbol* lookup(char* name){
  int index = hashFunction(name);
  Symbol* mySymbol = mySymTab->hashTable[index];
  int i;
  for (i=index; i>0; i--, mySymbol = mySymTab->hashTable[i]){ // TODO delete if not needed
    while (mySymbol != NULL){
      //printf("=======================mySymbol->name=%s, name=%s isActive=%d\n", mySymbol->name, name, mySymbol->isActive); //TODO delete
      if ((strcmp(mySymbol->name, name) == 0) && (mySymbol->isActive)){
        //printf("Lookup will return '%s'\n", mySymbol->name); // TODO delete
        return mySymbol;
        /* The implementation of insert is such, that every new Symbol
         * is inserted at the start of the bucket list. So the first
         * active Symbol that is encountered with the name we are looking
         * for, is sure to be the last declared of all Symbols with same
         * name.
         */
      }
      mySymbol = mySymbol->nextSymbol;
    }
  }
  return NULL;
}

Symbol* lookupInScope(char* name, int depth){
  int index = hashFunction(name);
  Symbol* mySymbol = mySymTab->hashTable[index];
  while (mySymbol != NULL){
    if ((strcmp(mySymbol->name, name) == 0) &&
        (mySymbol->declInScope == depth)    &&
        (mySymbol->isActive == 1)
    ){
      return mySymbol;
    }
    mySymbol = mySymbol->nextSymbol;
  }
  return NULL;
}

int isLibSymbol(char* name){
  int index = hashFunction(name);
  Symbol* mySymbol = mySymTab->hashTable[index];
  while (mySymbol != NULL){
    if ((strcmp(mySymbol->name, name) == 0) &&
        (mySymbol->isActive)/*TODO delete this rule may be not needed*/ &&
        (mySymbol->symbolType == LIB_FUNC)  )
    {
      return 1;
    }
    mySymbol = mySymbol->nextSymbol;
  }
  return 0;
}

void printSymbolList (Symbol* mySymbol){  
  while (mySymbol != NULL ){
    printf("line: %d scope: %d\t",mySymbol->declInLine,mySymbol->declInScope);
    switch (mySymbol->scopeSpace){
      case _PROGRAM:   printf("Program\t");         break;
      case _LOCAL:   printf("Local\t");             break;
      case _FORMAL:  printf("Formal\t");            break;
    }
    switch (mySymbol->symbolType){
      case VAR:    printf("Variable\t\t");          break;
      case FUNC:    printf("User Function\t\t");    break;
      case ARG:    printf("Formal  Argument\t\t");  break;
      case LIB_FUNC:  printf("Library Function\t"); break;
    }
    printf("'%s'\n", mySymbol->name);
    mySymbol = mySymbol->nextSymbol;
  }
}

void insertSymbolInBucket (Symbol* mySymbol,
      unsigned int bucket,
      SymbolTable* sortedSymTab
){
  assert(mySymbol);
  assert(sortedSymTab);

  mySymbol->nextSymbol = sortedSymTab->hashTable[bucket];
  sortedSymTab->hashTable[bucket] = mySymbol; // Inserts Symbol in Hash Table
  sortedSymTab->symbolCount++;
}

SymbolTable* createSortedSymbolTable (){
  SymbolTable* sortedSymTab = createSymbolTable();
  Symbol * mySymbol, * nextSymbol;
  int i;
  for (i=0; i<PRIME; i++){
    mySymbol = mySymTab->hashTable[i];
    while (mySymbol != NULL ){
      nextSymbol = mySymbol->nextSymbol;
      insertSymbolInBucket(
        mySymbol,
        mySymbol->declInLine,
        sortedSymTab);
      mySymbol = nextSymbol;
    }
  }
  return sortedSymTab;
}

void printSymbolTable (){
  puts("\n--- SYMBOL TABLE PRINTOUT -------------------------------------------------------------------\n");
  SymbolTable * sortedSymTab = createSortedSymbolTable();
  int i;
  for (i=0; i<PRIME;i++){
    printSymbolList(sortedSymTab->hashTable[i]);
  }
}

#endif
