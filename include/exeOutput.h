/* 
 * File:   binaryOutput.h
 *
 * Created on June 8, 2014, 10:16 PM
 */

#ifndef BINARYOUTPUT_H
#define  BINARYOUTPUT_H

#include <stdio.h>
#include <string.h>
#include "const_tables.h"
#include "vmarguments.h"

FILE * outfile; // A global pointer to the output file

/* Reads @instructions for instructions.h and parses them into an executable
 * binary alpha file named @FILENAME
 */
void avmbinaryfile (char *);

void      magicnumber   ();
void      arrays        ();
void      strings       ();
void      string        (char * str);
unsigned  size          (char * str);
void      numbers       ();
void      userfunctions ();
void      userfunc      (UserfuncContainer * userfunc);
void      libfunctions  ();
void      code          ();
void      instruction   (Instruction * instr);
void      opcode        (VMOPCODE op);
void      operand       (VMARG arg);

#endif  /* BINARYOUTPUT_H */

