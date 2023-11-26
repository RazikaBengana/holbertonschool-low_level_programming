#include "main.h"

/**
 * print_number - program that prints an integer
 *
 * @n: the positive integer to be printed
 *
 * Return: nothing (void)
 */

void print_number(int n)
{
	unsigned int absolute_value = n;

	if (n < 0)
	{
		_putchar('-');
		absolute_value = -num;
	}

	if ((absolute_value / 10) > 0)
		print_number(absolute_value / 10);

	_putchar((absolute_value % 10) + '0');
}