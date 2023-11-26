#include "main.h"

/**
 * print_line - program that draws a straight line in the terminal
 *
 * the line should end with a \n
 * if n is 0 or less, the function should only print \n
 *
 * @n: the number of times the character _ should be printed
 *
 * Return: nothing (void)
 */

void print_line(int n)
{

	int a;

	if (n > 0)
	{
		for (a = 0; a < n; a++)
		{
			_putchar ('_');
		}
		_putchar (10);
	}

	else
	{
		_putchar (10);
	}
}