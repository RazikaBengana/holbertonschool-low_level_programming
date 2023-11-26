#include "main.h"

/**
 * puts_half - program that prints half of a string, followed by a new line
 *
 * @str: the string to be selectively printed
 *
 * Return: nothing (void)
 */

void puts_half(char *str)
{
	int index, half_length, length;

	length = 0;

	for (index = 0; str[index] != '\0'; index++)
		length++;

	half_length = (length / 2);

	if ((length % 2) == 1)
		half_length = ((length + 1) / 2);

	for (index = half_length; str[index] != '\0'; index++)
		_putchar(str[index]);

	_putchar('\n');
}