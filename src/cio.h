#ifndef __CIO_H__
#define __CIO_H__

#include "libti.c"

#include "clib.c"

int __cio__returnValue;

char __cio__current_line = 0;

void clearscreen();

void resetcursor();

void newline();

void setPenCol(char);
void setPenRow(char);

void vputs(char*);

void print(char*);

void println(char*);

int getKey();

#endif
