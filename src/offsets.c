#ifndef _OFFSETS_C_
#define _OFFSETS_C_

#include "../include/offsets.h"


unsigned programVarsOffset 				= 0;
unsigned functionLocalsOffset 			= 0;
unsigned formalArgsOffset				= 0;
unsigned scopeSpaceCounter 				= 1;

enum SCOPE_SPACE currscopespace (){
	if 		(scopeSpaceCounter == 1)	{ return _PROGRAM; 	}
	else if (scopeSpaceCounter % 2 == 0){ return _FORMAL; 	}
	else								{ return _LOCAL; 	}
}

unsigned currscopeoffset (){
	switch (currscopespace()){
		case _PROGRAM	: return programVarsOffset;
		case _LOCAL		: return functionLocalsOffset;
		case _FORMAL	: return formalArgsOffset;
		default			: assert(0);
	}
	assert(0);
	return 0;			// No mans land
}

void incurrscopeoffset (){
	switch (currscopespace()){
		case _PROGRAM	: ++programVarsOffset; 		break;
		case _LOCAL		: ++functionLocalsOffset;	break;
		case _FORMAL	: ++formalArgsOffset; 		break;
		default			: assert(0);
	}
}

void enterscopespace (){ ++scopeSpaceCounter; }

void exitscopespace	(){
	assert(scopeSpaceCounter > 1);
	--scopeSpaceCounter;
}

void resetformalargsoffset (){ formalArgsOffset = 0;	}

void resetfunctionlocalssoffset (){ functionLocalsOffset = 0;}

void restorecurrscopeoffset (unsigned n){
	switch (currscopespace()){
		case _PROGRAM	: programVarsOffset 	= n; break;
		case _LOCAL		: functionLocalsOffset 	= n; break;
		case _FORMAL	: formalArgsOffset 		= n; break;
		default			: assert(0);
	}
}

#endif
