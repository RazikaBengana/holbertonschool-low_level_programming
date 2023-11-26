#include "main.h"

/**
 * times_table - program that prints the 9 times table, starting with 0
 *
 * Return: nothing (void)
 */

void times_table(void)
{
	int rows = 0, columns = 0, multi;

	for (rows = 0; rows <= 9; rows++)
	{
		_putchar('0');

		for (columns = 1; columns <= 9; columns++)
		{
			multi = rows * columns;

			if (multi < 10)
			{
				_putchar(44);
				_putchar(' ');
				_putchar(' ');
				_putchar(multi % 10 + '0');
			}

			else if (multi >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(multi / 10 + '0');
				_putchar(multi % 10 + '0');
			}
		}
		_putchar(10);
	}
}