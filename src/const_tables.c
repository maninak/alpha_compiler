#ifndef _CONST_TABLES_C_
#define _CONST_TABLES_C_

#include "../include/const_tables.h"


StrContainer *      string_table    = NULL; // The table holding strings
unsigned            max_STR         = 0;    // The maximum capacity of the array
unsigned            curr_STR        = 0;    // The next empty slot in the array to input a quad

NumberContainer *   number_table    = NULL; // The table holding numbers
unsigned            max_NUM         = 0;    // The maximum capacity of the array
unsigned            curr_NUM        = 0;    // The next empty slot in the array to input a quad

LibfuncContainer *  libfuncs_table  = NULL;  // The table holding library functions
unsigned            max_LIB         = 0;     // The maximum capacity of the array
unsigned            curr_LIB        = 0;     // The next empty slot in the array to input a quad

UserfuncContainer * usrfuncs_table  = NULL;  // The table holding userFunctions
unsigned            max_USR         = 0;     // The maximum capacity of the array
unsigned            curr_USR        = 0;     // The next empty slot in the array to input a quad


//STRING TABLE
unsigned add_new_STR(char * s){
  if (curr_STR == max_STR){ expand_STR(); }
  string_table[curr_STR].string = s;
  return curr_STR++;
}

void expand_STR(){
  assert(max_STR == curr_STR);


  StrContainer * p = (StrContainer *) malloc(NEW_SIZE_STR);

  assert(p); //TODO delete
  if (string_table) {
    memcpy(p, string_table, CURR_SIZE_STR);
    free(string_table);
  }
  string_table = p;
  max_STR += EXPAND_SIZE;
}

//NUMBER TABLE
unsigned add_new_NUM(double num){
  if (curr_NUM == max_NUM){ expand_NUM(); }

  number_table[curr_NUM].number = num;
  return curr_NUM++;
}

void expand_NUM(){
  assert(max_NUM == curr_NUM);

  NumberContainer * p = (NumberContainer *) malloc(NEW_SIZE_NUM);

  assert(p); //TODO delete
  if (number_table) {
    memcpy(p, number_table, CURR_SIZE_NUM);
    free(number_table);
  }
  number_table = p;
  max_NUM += EXPAND_SIZE;
}

//LIB FUNCS TABLE
unsigned add_new_LIB(char * libName){
  if (curr_LIB == max_LIB){ expand_LIB(); }

  libfuncs_table[curr_LIB].libfunc_name = libName;
  return curr_LIB++;
}

void expand_LIB(){
  assert(max_LIB == curr_LIB);


  LibfuncContainer * p = (LibfuncContainer *) malloc(NEW_SIZE_LIB);

  assert(p); //TODO delete
  if (libfuncs_table) {
    memcpy(p, libfuncs_table, CURR_SIZE_LIB);
    free(libfuncs_table);
  }
  libfuncs_table = p;
  max_LIB += EXPAND_SIZE;
}

unsigned add_new_USR(unsigned taddress,unsigned locals,char * funcName){
  unsigned i;
  
  for (i=0; i<curr_USR; i++){  //An yparxei hdh h sunarthsh auth epistrefei ws val to index tou pinaka pou einai auth h sunarthsh
    if ((usrfuncs_table[i].taddress == taddress)  &&
        (usrfuncs_table[i].locals   == locals)    &&
        (strcmp(usrfuncs_table[i].name,funcName) == 0)
    ){
      return i;
    }
  }
  if (curr_USR == max_USR){ expand_USR(); }
  
  usrfuncs_table[curr_USR].taddress = taddress;
  usrfuncs_table[curr_USR].locals = locals;
  usrfuncs_table[curr_USR].name = funcName;
  
  return curr_USR++;
}

void expand_USR(){
  assert(max_USR == curr_USR);


  UserfuncContainer * p = (UserfuncContainer *) malloc(NEW_SIZE_USR);

  assert(p); //TODO delete
  if (usrfuncs_table) {
    memcpy(p, usrfuncs_table, CURR_SIZE_USR);
    free(usrfuncs_table);
  }
  usrfuncs_table = p;
  max_USR += EXPAND_SIZE;
}

void printConstTables(){
  unsigned i;

  printf("\nString Array\n");
  for(i=0; i<curr_STR; i++){
      printf("%d: %s\n",i,string_table[i].string);
  }

  printf("\nNumber Array\n");
  for (i=0; i<curr_NUM; i++){
    printf("%d: %f\n",i,number_table[i].number);
  }
  printf("\nLibrary Functions Array\n");
  for (i=0; i<curr_LIB; i++){
    printf("%d: %s\n",i,libfuncs_table[i].libfunc_name);
  }
  printf("\nUser Functions Array\n");
  for (i=0; i<curr_USR; i++){
    printf("%d: T-ad:%u Loc:%u %s\n",i,usrfuncs_table[i].taddress,usrfuncs_table[i].locals,usrfuncs_table[i].name);
  }
}

#endif
