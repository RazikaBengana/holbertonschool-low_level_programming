#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all the numbers of base 16 in lowercase, followed by a new line
 *
 * Return: 0 (success)
 */

int main(void)
{
	char a = 'a';

	int num;

	for (num = 0; num < 16; num++)
	{
		if (num < 10)
		{
			putchar(num + '0');
		}

		else
		{
			putchar(a);
			a++;
		}
	}

	putchar('\n');

	return (0);
}