#ifndef __LIBTI_C__
#define __LIBTI_C__

#include "libti.h"

void assignAToVar(int* var) {
	var;
	__asm
		ld	d,4 (ix)
		ld	e,5 (ix)
		ld	l, d
		ld	h, e
		ld	(hl),a
		inc	hl
		ld	(hl),#0x00
	__endasm;
}

#endif
