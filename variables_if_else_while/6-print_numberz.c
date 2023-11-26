#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all single digit numbers of base 10 starting from 0, followed by a new line
 * (with putchar)
 *
 * Return: 0 (success)
 */

int main(void)
{
	int a;

	for (a = 0; a < 10; a++)
	{
		putchar(a + '0');
	}

	putchar('\n');

	return (0);
}