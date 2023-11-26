#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints the alphabet in lowercase, and then in uppercase, followed by a new line
 *
 * Return: 0 (success)
 */

int main(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
		putchar(a);

	for (a = 'A'; a <= 'Z'; a++)
		putchar(a);

	putchar('\n');

	return (0);
}