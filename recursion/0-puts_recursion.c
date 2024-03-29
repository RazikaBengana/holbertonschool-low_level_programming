#include "main.h"

/**
 * _puts_recursion - program that prints a string, followed by a new line
 *
 * @s: the string
 *
 * Return: nothing (void)
 */

void _puts_recursion(char *s)
{

	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}