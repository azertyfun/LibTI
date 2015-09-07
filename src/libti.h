#ifndef __LIBTI_H__
#define __LIBTI_H__

#include "ti84p_mappings.h"

int returnValue;

void assignAToVar(int*);

#define bcall(__LABEL__) \
	__asm rst 40 \
	.dw __LABEL__ __endasm

#include "clib.c"
#include "cio.c"

#endif
