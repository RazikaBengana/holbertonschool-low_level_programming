#include "../main.h"

/**
 * _isdigit - program that checks for a digit (0 through 9)
 *
 * @c: the character to be tested
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	else
		return (0);
}