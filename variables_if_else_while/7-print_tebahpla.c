#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints the lowercase alphabet in reverse, followed by a new line
 *
 * Return: 0 (success)
 */

int main(void)
{
	char a;

	for (a = 'z'; a >= 'a'; a--)
		putchar(a);

	putchar('\n');

	return (0);
}