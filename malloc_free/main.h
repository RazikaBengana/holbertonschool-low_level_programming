#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>


/* _putchar function (if needed) */
int _putchar(char c);

char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);

/* advanced tasks */
char *argstostr(int argc, char **argv);
int word_length(char *str);
int count_words(char *str);
char **strtow(char *str);


#endif /* MAIN_H */