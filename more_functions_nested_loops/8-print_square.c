#include "main.h"

/**
 * print_square - program that prints a square, followed by a new line
 *
 * if size is 0 or less, the function should print only a new line
 * we have to use the character # to print the square
 *
 * @size: the size of the square
 *
 * Return: nothing (void)
 */

void print_square(int size)
{

	int i, j;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{

			for (j = 0; j < size; j++)
			{
				_putchar ('#');
			}
		}
		_putchar (10);
	}
}