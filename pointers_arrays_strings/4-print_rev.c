#include "main.h"

/**
 * print_rev - program that prints a string, in reverse, followed by a new line
 *
 * @s: the string to be printed
 *
 * Return: nothing (void)
 */

void print_rev(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	while (length)
		_putchar(s[--length]);

	_putchar('\n');
}