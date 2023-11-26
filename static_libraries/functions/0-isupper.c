#include "../main.h"

/**
 * _isupper - program that checks for uppercase character
 *
 * @c: the character to be tested
 *
 * Return: 1 if the character is uppercase, 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	else
		return (0);
}