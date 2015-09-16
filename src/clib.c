#ifndef __CLIB_C__
#define __CLIB_C__

#include "clib.h"

int strlen(char s[]) {
	#define i __clib__i

	i = 0;
	while(s[i] != '\0')
		++i;
	return i;

	#undef i
}

void reverse(char s[]) {
	//For some reason I don't ahve the patience to investigate, var reuse makes it not work.
	int i, j;
	char c;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

char* itoa(int s_n, char s[]) {
	#define i __clib__i
	#define n __clib__j

	if(s_n < 0)
		n = -s_n;
	else
		n = s_n;

    i = 0;

	do {
		s[i++] = n % 10 + '0';
	} while((n /= 10) > 0);

	if(s_n < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);

	return s;

	#undef i
	#undef n
}

//http://stackoverflow.com/questions/12791077/atoi-implementation-in-c
int atoi(char *p) {
	#define k __clib__returnval

	k = 0;
	__clib__j = 0;

	if(*p == '-' || *p == '+') {
		if(*p == '-') {
			__clib__j = 1;
		}
		else {
			__clib__j = 0;
		}
		p++;
	}

	while(*p) {
		k = (k << 3) + (k << 1) + (*p) - '0';
		p++;
	}

	return (__clib__j ? -k : k);

	#undef k
}

#endif
