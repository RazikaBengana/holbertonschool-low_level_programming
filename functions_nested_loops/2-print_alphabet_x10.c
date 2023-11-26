#include "main.h"

/**
 * print_alphabet_x10 - program that prints 10 times the alphabet, in lowercase, followed by a new line
 *
 * Return: nothing (void)
 */

void print_alphabet_x10(void)
{
	int count = 0;
	char c;

	while (count++ <= 9)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar(10);
	}
}