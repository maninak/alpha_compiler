#ifndef _VMARGUMENTS_C_
#define _VMARGUMENTS_C_

#include "../include/vmarguments.h"
#include "../include/const_tables.h"

void make_operand(Expr* e, VMARG * arg){
	assert(arg);
	
    if (e == NULL){
		reset_operand(arg);
	}
	else {
		switch (e->type){
			case var_e:
			case tableitem_e:
			case arithmeticexpr_e:
			case boolexpr_e:
			case newtable_e:
                        case assignexpr_e:
                                                assert(e->sym);
						arg->val = e->sym->offset;
						switch (e->sym->scopeSpace){
						case _PROGRAM:
								arg->type = global_a;
								break;
						case _LOCAL:
								arg->type = local_a;
								break;
						case _FORMAL:
								arg->type = formal_a;
								break;
						default:	assert(0);
						}
											break;
			case boolconst_e:
						arg->val = e->boolconst;
						arg->type = bool_a;
						break;	
			case stringconst_e:
						arg->val = add_new_STR(e->strconst);
						arg->type = string_a;
						break;	
			case numconst_e:
						arg->val = add_new_NUM(e->numconst);
						arg->type = number_a;
						break;
			case nil_e:		
						arg->type = nil_a;
						break;				
			case programfunc_e:
						arg->type = programfunc_a;
						arg->val = add_new_USR(e->sym->taddress,e->sym->totalLocals,e->sym->name);  //Add the user function to the userFunctionTable
						break;
			case libraryfunc_e:
						arg->type = libfunc_a;
						arg->val = add_new_LIB(e->sym->name);
						break;
			default:                assert(0);
		}
	}
}

void	make_numberOperand(VMARG* arg, double val){	
	arg->val = add_new_NUM(val);
	arg->type = number_a;
}
void	make_boolOperand(VMARG* arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}
void	make_retvalOperand(VMARG* arg){
	arg->type = retval_a;
}
void    reset_operand(VMARG* arg){
    arg->type = empty_a;
}
#endif