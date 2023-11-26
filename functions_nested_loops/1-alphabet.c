#include "main.h"

/**
 * print_alphabet - program that prints the alphabet, in lowercase, followed by a new line
 *
 * Return: nothing (void)
 */

void print_alphabet(void)
{
	char a;

	for (a = 97; a <= 122 ; a++)
	{
		_putchar(a);
	}

	_putchar(10);

}