#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/* _putchar function (if needed) */
int _putchar(char c);

void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

/* advanced tasks */
void print_bytes_from_address(void *address, int num_bytes);


#endif /* FUNCTION_POINTERS_H */