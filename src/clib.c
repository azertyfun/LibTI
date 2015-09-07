#ifndef __CLIB_C__
#define __CLIB_C__

#include "clib.h"

int strlen(char s[]) {
	__clib__i = 0;
	while(s[__clib__i] != '\0')
		++__clib__i;
	return __clib__i;
}

void reverse(char s[]) {
	int __clib__i, __clib__j;
	char c;

	for(__clib__i = 0, __clib__j = strlen(s) - 1; __clib__i < __clib__j; __clib__i++, __clib__j--) {
		c = s[__clib__i];
		s[__clib__i] = s[__clib__j];
		s[__clib__j] = c;
	}
}

char* itoa(unsigned int n, char s[]) {
    __clib__i = 0;
	do {
		s[__clib__i++] = n % 10 + '0';
	} while((n /=10) > 0);
	s[__clib__i] = '\0';
	reverse(s);

	return s;
}

#endif
