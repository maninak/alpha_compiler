#ifndef GENERATOR_H
#define  GENERATOR_H
#include <stdio.h>
#include "quads.h"
#include "SymbolTable.h"
#include "vmarguments.h"
#include "instructions.h"
#include "SymbolStack.h"
#include "const_tables.h"

extern SymbolStack * funcStack; //Symbol stack for keeping nested functions
typedef void (*generator_func_t)(Quad *);


/*
 * Returns the number of the quad being proccesed at the time..
 */
extern unsigned currprocessedquad();

/*
 * Generates the corresponding instruction of the input quad and emits it
 * in the instruction's table
 */
extern void generate(IOPCODE,Quad*);
/*
 * Calls the generate with the appropriate opcode
 */
extern void generate_ADD(Quad*);
extern void generate_SUB(Quad*);
extern void generate_MUL(Quad*);
extern void generate_DIV(Quad*);
extern void generate_MOD(Quad*);
extern void generate_UMINUS(Quad* quad);
extern void generate_NEWTABLE(Quad*);
extern void generate_TABLEGETELEM(Quad*);
extern void generate_TABLESETELEM(Quad*);
extern void generate_ASSIGN(Quad*);
extern void generate_NOP();

/*
 * Generates the corresponding instruction of the input quad and emits it
 * in the instruction's table.(For relational quads only)
 */
extern void   generate_relational(IOPCODE,Quad*);

/*
 * Calls the generate_relational with the appropriate opcode
 */
extern void generate_JUMP(Quad*);
extern void generate_IF_EQ(Quad*);
extern void generate_IF_NOTEQ(Quad*);
extern void generate_IF_GREATER(Quad*);
extern void generate_IF_GREATEREQ(Quad*);
extern void generate_IF_LESS(Quad*);
extern void generate_IF_LESSEQ(Quad*);
extern void generate_PARAM(Quad*);
extern void generate_CALL(Quad*);
extern void generate_GETRETVAL(Quad*);
extern void generate_FUNCSTART(Quad*);
extern void generate_RETURN(Quad*);
extern void generate_FUNCEND(Quad*);

/*
 * Patches all the incomplete function jumps
 */
extern void backpatch_I(IntStack *,unsigned);

/*
 * Calls the generate functions according to every quad in the quads Table
 */
extern void generateInstructionTable();
#endif  /* GENERATOR_H */