#ifndef __CIO_C__
#define __CIO_C__

#include "cio.h"

void clearscreen() {
	bcall(_clrlcdf);
	resetcursor();
}

void resetcursor() {
	//bcall(_homeup);
	__cio__current_line = 0;
}

void newline() {
	__cio__current_line += 6;
}

void setPenCol(char col) {
	col;
	__asm
		ld a, 4(ix)
		ld (pencol), a
	__endasm;
}

void setPenRow(char row) {
	row;
	__asm
		ld a, 4(ix)
		ld (penrow), a
	__endasm;
}

void vputs(char* s) {
	s;
	__asm
		ld a, 4(ix)
		ld h, 5(ix)
	__endasm;
	bcall(_vputs);
}

void print(char* s) {
	setPenRow(__cio__current_line);
	setPenCol(0);
	vputs(s);
}

void println(char* s) {
	print(s);
	newline();
}

int getKey() {
	bcall(_getkey);
	assignAToVar(&__cio__returnValue);
	return __cio__returnValue;
}

#endif
