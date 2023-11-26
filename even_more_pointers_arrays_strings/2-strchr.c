#include "main.h"

/**
 * _strchr - program that locates a character in a string
 *
 * @s: the string to search in
 * @c: the character to locate
 *
 * Return: a pointer to the first occurrence of the character c in the string s, or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] == c)
			return (&s[index]);
	}

	return (NULL);
}