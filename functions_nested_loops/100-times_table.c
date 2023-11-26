#include "main.h"

/**
 * print_times_table - program that prints the n times table, starting with 0
 *
 * if n is greater than 15 or less than 0 the function should not print anything
 *
 * @n: the upper limit for the times table (0 to 15)
 *
 * Return: nothing (void)
 */

void print_times_table(int n)
{
	int multiplicand, multiplier, product;

	if (n >= 0 && n <= 15)
	{
		for (multiplicand = 0; multiplicand <= n; multiplicand++)
		{
			_putchar('0');

			for (multiplier = 1; multiplier <= n; multiplier++)
			{
				_putchar(',');
				_putchar(' ');

				product = multiplicand * multiplier;

				if (product <= 99)
					_putchar(' ');
				if (product <= 9)
					_putchar(' ');
				if (product >= 100)
				{
					_putchar((product / 100) + '0');
					_putchar(((product / 10) % 10) + '0');
				}

				else if (product <= 99 && product >= 10)
				{
					_putchar((product / 10) + '0');
				}
				_putchar((product % 10) + '0');
			}

			_putchar('\n');
		}
	}
}