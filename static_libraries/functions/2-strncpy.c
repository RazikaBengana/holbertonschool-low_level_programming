#include "../main.h"

/**
 * _strncpy - program that copies a string
 *
 * @src: the source string
 * @dest: the destination string
 * @n: an integer that represents the maximum number of characters to copy
 *
 * Return: the pointer to the destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int index;

	for (index = 0; index < n && src[index] != '\0'; index++)
		dest[index] = src[index];

	for ( ; index < n; index++)
		dest[index] = '\0';

	return (dest);
}