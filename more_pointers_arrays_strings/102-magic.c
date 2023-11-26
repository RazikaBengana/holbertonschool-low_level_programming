#include "main.h"

/**
 * main - the entry point
 *
 * in this program, we just have to add one line to this provided code,
 * so that the program prints a[2] = 98, followed by a new line
 *
 * we are not allowed to use the variable a in the new line of code
 * we are not allowed to modify the variable p
 * we can only write one statement
 * we are not allowed to use "," (comma)
 * we are not allowed to code anything else than the line of expected line of code at the expected line
 *
 * Return: 0 (success)
 */

int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/*
	 * write your line of code here...
	 * Remember:
	 * - you are not allowed to use a
	 * - you are not allowed to modify p
	 * - only one statement
	 * - you are not allowed to code anything else than this line of code
	 */
	*(p + 5) = 98;
	/* ...so that this prints 98\n */

	printf("a[2] = %d\n", a[2]);
	return (0);
}