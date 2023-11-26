#include "main.h"

/**
 * _strspn - program that gets the length of a prefix substring
 *
 * @s: the string to search in
 * @accept: the string containing characters to include in the prefix substring
 *
 * Return: the number of bytes in the initial segment of s which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int str_index, accept_index, length = 0;

	for (str_index = 0; s[str_index] != '\0'; str_index++)
	{
		if (s[str_index] != ' ')
		{
			for (accept_index = 0; accept[accept_index] != '\0'; accept_index++)
			{
				if (s[str_index] == accept[accept_index])
					length++;
			}
		}

		else
			return (length);
	}

	return (length);
}