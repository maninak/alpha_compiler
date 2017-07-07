#ifndef VMARGUMENTS_H
#define  VMARGUMENTS_H

#include <assert.h>
#include "expressions.h"
#include "quads.h"

/*
 * Enum values for the field type of vmargs
 */
typedef enum VMARG_TYPE {
  programfunc_a,      libfunc_a,        retval_a,
  global_a,           local_a,          label_a,
  formal_a,           number_a,         bool_a,
  string_a,           nil_a,            empty_a

}VMARG_TYPE;
/*
 * Struct of vmarg
 */
typedef struct VMARG{

  VMARG_TYPE  type;   //Type of the argument
  unsigned    val;    //Value of the argument.In some occasion is the index of the arg in the proper Const_Table
}VMARG;

/*
 * Converts the expr into a vmarg
 */
void    make_operand(Expr*, VMARG*);
/*
 * Makes a vmarg with type number_a and val the index of the number in the numberTable
 */
void  make_numberOperand(VMARG*,double);
/*
 * Makes a vmarg with type bool_a and val the unsigned val of the parameter
 */
void  make_boolOperand(VMARG*,unsigned);
/*
 * Makes a vmarg with type retval_a
 */
void    make_retvalOperand(VMARG*);
/*
 * Makes a vmarg with type empty. Reseting it.
 */
void    reset_operand(VMARG*);
#endif  /* FINAL_CODE_H */
