#include "main.h"

/**
 * _strncat - program that concatenates two strings
 *
 * the _strncat function is similar to the _strcat function,
 * except that it will use at most n bytes from src,
 * and src does not need to be null-terminated if it contains n or more bytes
 *
 * @src: the source string
 * @dest: the destination string
 * @n: the number of bytes
 *
 * Return: a pointer to the resulting destination string
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_length, src_length;

	for (dest_length = 0; dest[dest_length] != '\0'; dest_length++)
		;

	for (src_length = 0; src[src_length] && src_length < n; src_length++)
	{
		dest[dest_length] = src[src_length];
		dest_length++;
	}

	return (dest);
}