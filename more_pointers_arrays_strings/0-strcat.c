#include "main.h"

/**
 * _strcat - program that concatenates two strings
 *
 * the function appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte
 *
 * @src: the source string
 * @dest: the destination string
 *
 * Return: a pointer to the resulting destination string
 */

char *_strcat(char *dest, char *src)
{
	int dest_length, src_length;

	for (dest_length = 0; dest[dest_length] != '\0'; dest_length++)
		;

	for (src_length = 0; src[src_length] != '\0'; src_length++)
	{
		dest[dest_length] = src[src_length];
		dest_length++;
	}

	dest[dest_length] = '\0';

	return (dest);
}