#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all possible combinations of single-digit numbers
 *
 * numbers must be separated by a comma, followed by a space
 * numbers should be printed in ascending order
 *
 * Return: 0 (success)
 */

int main(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
		putchar(a + '0');

		if (a < 9)
		{
			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}