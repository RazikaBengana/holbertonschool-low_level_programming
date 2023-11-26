#include "main.h"

/**
 * _islower - program that checks for lowercase character
 *
 * @c: the character to be tested
 *
 * Return: 1 if the character is in lowercase, 0 otherwise
 */

int _islower(int c)
{

	if (c >= 97 && c <= 122)
		return (1);

	else
		return (0);
}