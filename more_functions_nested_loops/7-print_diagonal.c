#include "main.h"

/**
 * print_diagonal - program that draws a diagonal line on the terminal
 *
 * the diagonal should end with a \n
 * if n is 0 or less, the function should only print a \n
 *
 * @n: the number of times the character \ should be printed
 *
 * Return: nothing (void)
 */

void print_diagonal(int n)
{
	int a, j;

	if (n > 0)
	{
		for (a = 0; a < n; a++)
		{
			for (j = 0; j < a; j++)
			{
				_putchar (' ');
			}
			_putchar (92);
			_putchar (10);
		}
	}

	else
	{
		_putchar (10);
	}

}