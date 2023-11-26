#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints the alphabet in lowercase, followed by a new line
 * (all the letters except q and e)
 *
 * Return: 0 (success)
 */

int main(void)
{
	char a;

	for (a = 'a'; a <= 'z'; a++)
	{
		if (a != 'q' && a != 'e')
		{
			putchar(a);
		}
	}

	putchar('\n');

	return (0);
}