#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>


/* _putchar function (if needed) */
int _putchar(char c);

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);

/* advanced tasks */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
unsigned int *allocateAndInitializeDigitArray(size_t size);
void multiplyStringsAsIntegers(unsigned int *productDigits, char *multiplierDigits,
			       char *multiplicandDigits, size_t multiplierLength,
			       size_t multiplicandLength);
int isPositiveIntegerString(char *s);
void printError(int statusCode);


#endif /* MAIN_H */