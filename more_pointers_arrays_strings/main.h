#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stddef.h>
#include <unistd.h>


/* _putchar function (if needed) */
int _putchar(char c);

char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void reverse_array(int *a, int n);
char *string_toupper(char *);
char *cap_string(char *);
char *leet(char *);

/* advanced tasks */
char *rot13(char *input);
void print_number(int n);
char *infinite_add(char *num1_str, char *num2_str, char *result_str,
		   int result_size);
void print_buffer(char *buffer, int size);


#endif /* MAIN_H */