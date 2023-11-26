#include "main.h"

/**
 * print_number - program that prints an integer to the standard output
 *
 * @n: the integer to be printed
 *
 * Return: nothing (void)
 */

void print_number(int n)
{
	unsigned int positive_num, current_digit, divisor;

	if (n < 0)
	{
		_putchar('-');
		positive_num = (unsigned int)(-n);
	}

	else
	{
		positive_num = (unsigned int)n;
	}

	current_digit = positive_num;
	divisor = 1;

	while (current_digit > 9)
	{
		current_digit /= 10;
		divisor *= 10;
	}

	for (; divisor >= 1; divisor /= 10)
	{
		_putchar(((positive_num / divisor) % 10) + '0');
	}
}