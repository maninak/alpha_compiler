#ifndef _BINARYOUTPUT_C_
#define	_BINARYOUTPUT_C_

#include "../include/exeOutput.h"

void avmbinaryfile (char * filename){
	assert(filename);
//	puts("avmbinaryfile"); //TODO delete
//	strcat(filename, ".abc");
//	puts("strcat"); //TODO delete
	outfile = fopen("out.abc", "wb");
	magicnumber();
	arrays();
	code();
	fclose(outfile);
}

void magicnumber (){
	unsigned magicNumber = 1337;
	fwrite(&magicNumber, sizeof(magicNumber), 1, outfile);
}

void arrays (){
	strings();
	numbers();
	userfunctions();
	libfunctions();
}

void strings (){
	fwrite(&curr_STR, sizeof(curr_STR), 1, outfile);	// a.k.a. total
	int i;
	for (i=0; i<curr_STR; i++){
		string(string_table[i].string);
	}
}

void string (char * str){
	unsigned charCount = size(str);
	fwrite(str, sizeof(char), charCount, outfile);
}

unsigned size (char * str){
	assert(str);
	unsigned charCount = sizeof(str);
	fwrite(&charCount, sizeof(charCount), 1, outfile);
	return charCount;
}

void numbers (){
	fwrite(&curr_NUM, sizeof(curr_NUM), 1, outfile);	// a.k.a. total
	int i;
	for (i=0; i<curr_NUM; i++){
		fwrite(&number_table[i].number, sizeof(double), 1, outfile);
	}
}

void userfunctions (){
	fwrite(&curr_USR, sizeof(curr_USR), 1, outfile);	// a.k.a. total
	int i;
	for (i=0; i<curr_USR; i++){
		userfunc(&usrfuncs_table[i]); //TODO check if & solves error correctly
	}
}

void userfunc (UserfuncContainer * userfunc){
	assert(userfunc);
	fwrite(&userfunc->taddress, sizeof(unsigned), 1, outfile);	// a.k.a. address
	fwrite(&userfunc->locals,   sizeof(unsigned), 1, outfile);	// a.k.a. localsize
	string(userfunc->name);										// a.k.a. id
}

void libfunctions (){
	fwrite(&curr_LIB, sizeof(curr_LIB), 1, outfile);	// a.k.a. total	
	int i;
	for (i=0; i<curr_LIB; i++){
		string(libfuncs_table[i].libfunc_name);
	}
}

void code (){
	fwrite(&currInstruction, sizeof(currInstruction), 1, outfile);// a.k.a. total		
	int i;
	for (i=0; i<currInstruction; i++){
		instruction(&instructions[i]);
	}	
}

void instruction (Instruction * instr){
	assert(instr);
	opcode(instr->opcode);
	operand(instr->arg1);
	operand(instr->arg2);
	operand(instr->result);
}

void opcode (VMOPCODE op){
	fwrite(&op, sizeof(op), 1, outfile);
}

void operand (VMARG arg){
	fwrite(&arg.type, sizeof(arg.type), 1, outfile);
	fwrite(&arg.val,  sizeof(arg.val) , 1, outfile);
}

#endif //_BINARYOUTPUT_C_
