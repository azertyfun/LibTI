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
	setPenRow(0);
	setPenCol(0);
}

void newline() {
	__cio__current_line += 6;
	setPenCol(0);
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
		ld l, 4(ix)
		ld h, 5(ix)
	__endasm;
	bcall(_vputs);
}

void vputc(char c) {
	c;
	__asm
		//ld a, 4(ix)
		ld a, 4(ix)
	__endasm;
	bcall(_vputmap);
}

void printc(char c) {
	setPenRow(__cio__current_line);
	vputc(c);
}

void print(char* s) {
	setPenRow(__cio__current_line);
	//setPenCol(0);
	vputs(s);
}

void println(char* s) {
	print(s);
	newline();
}

//This function only supports \n, no fancy variable integration or whatever.
void printf(char* s) {
	#define i __cio__i
	#define length __cio__j

	length = strlen(s);
	for(i = 0; i < length; ++i) {
		if(*(s + i) == '\n') {
			newline();
			setPenRow(__cio__current_line);
		}
		else
			printc(*(s + i));
	}

	#undef i
	#undef length
}

int getKey() {
	bcall(_getkey);
	assignAToVar(&__cio__returnValue);
	return __cio__returnValue;
}

int getInt() {
	#define i __cio__i
	#define key __cio__j
	#define buffer __cio__buffer

	i = 0;
	do {
		key = getKey();
		if(key >= DIGIT_0 && key <= DIGIT_0 + 9) {
			buffer[i++] = key - DIGIT_0 + '0';
			printc(buffer[i - 1]);
		} else if((key == 140 || key == 129) && i == 0) {
			buffer[i++] = '-';
			printc('-');
		}
	} while(key != 5);
	buffer[i] = '\0';

	newline();

	i = atoi(buffer);

	return i;

	#undef i
	#undef key
	#undef buffer
}

#endif
