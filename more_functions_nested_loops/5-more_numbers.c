#include "main.h"

/**
 * more_numbers - program that prints 10 times the numbers, from 0 to 14, followed by a new line
 *
 * Return: nothing (void)
 */

void more_numbers(void)
{
	int row, number;

	for (row = 0; row < 10; row++)
	{
		for (number = 0; number <= 14; number++)
		{
			if (number >= 10)
			{
				_putchar((number / 10) + '0');
			}
			_putchar((number % 10) + '0');
		}
		_putchar(10);
	}
}