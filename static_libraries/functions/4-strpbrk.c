#include "../main.h"

/**
 * _strpbrk - program that searches a string for any of a set of bytes
 *
 * the _strpbrk function locates the first occurrence in the string s of any of the bytes in the string accept
 *
 * @s: the string to search in
 * @accept: the string containing bytes to search for in 's'
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int index;

	while (*s)
	{

		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
				return (s);
		}
		s++;
	}

	return (NULL);
}