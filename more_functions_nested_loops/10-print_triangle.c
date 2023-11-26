#include "main.h"

/**
 * print_triangle - program that prints a triangle, followed by a new line
 *
 * if size is 0 or less, the function should print only a new line
 * we have to use the character # to print the triangle
 *
 * @size: the size of the triangle
 *
 * Return: nothing (void)
 */

void print_triangle(int size)
{

	int i, j, k;

	for (i = 1; i <= size; i++)
	{
		for (k = size - i; k >= 1; k--)
		{
			_putchar(' ');
		}

		for (j = 1; j <= i; j++)
		{
			_putchar('#');
		}
		_putchar(10);
	}

	if (size <= 0)
	{
		_putchar (10);
	}
}