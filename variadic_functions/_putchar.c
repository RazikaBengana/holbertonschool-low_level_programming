#include "variadic_functions.h"

/**
 * _putchar - program that writes a character to the standard output (stdout)
 *
 * @c: the character to print
 *
 * Return: on success, returns the number of bytes written (always 1);
 *         on error, -1 is returned, and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}