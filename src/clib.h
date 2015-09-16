#ifndef __CLIB_H__
#define __CLIB_H__

int __clib__i;
int __clib__j;
int __clib__returnval;
char __clib__c;

int strlen(char[]);

void reverse(char[]);

int __clib__itoa_sign;
char* itoa(int, char[]);
int atoi(char*);

#endif
