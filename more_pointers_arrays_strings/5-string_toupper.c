#include "main.h"

/**
 * string_toupper - program that changes all lowercase letters of a string to uppercase
 *
 * @s: the string to be converted
 *
 * Return: the pointer to the converted string
 */

char *string_toupper(char *s)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] >= 97 && s[index] <= 122)
			s[index] -= 32;
	}

	return (s);
}