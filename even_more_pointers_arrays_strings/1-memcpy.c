#include "main.h"

/**
 * _memcpy - program that copies memory area
 *
 * the _memcpy function copies n bytes from memory area src to memory area dest
 *
 * @dest: the destination memory area
 * @src: the source memory area
 * @n: the number of bytes to be copied
 *
 * Return: a pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
		dest[index] = src[index];

	return (dest);
}