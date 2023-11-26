#include "main.h"

/**
* print_most_numbers - program that prints the numbers, from 0 to 9, followed by a new line
* (except 2 and 4)
*
* Return: nothing (void)
*/

void print_most_numbers(void)
{
	int number;

	number = 0;

	while (number < 10)
	{
		if (number != 2 && number != 4)
		{
			_putchar (number + '0');
		}
		number++;
	}
	_putchar ('\n');
}