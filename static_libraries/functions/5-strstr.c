#include "../main.h"

/**
 * _strstr - program that locates a substring
 *
 * the _strstr function finds the first occurrence of the substring needle in the string haystack;
 * the terminating null bytes (\0) are not compared
 *
 * @haystack: the string to search in
 * @needle: the substring to locate within 'haystack'
 *
 * Return: a pointer to the beginning of the located substring, or NULL if the substring is not found
 */

char *_strstr(char *haystack, char *needle)
{
	int needle_length = 0;
	int haystack_length = 0;

	while (needle[needle_length] != '\0')
		needle_length++;

	while (haystack[haystack_length] != '\0')
	{
		int index;

		for (index = 0; needle[index] != '\0'; index++)
		{
			if (haystack[haystack_length + index] != needle[index])
				break;
		}

		if (index != needle_length)
			haystack_length++;

		else
			return &haystack[haystack_length];
	}

	return (NULL);
}