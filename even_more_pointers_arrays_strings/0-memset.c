#include "main.h"

/**
 * _memset - program that fills memory with a constant byte
 *
 * the _memset function fills the first n bytes of the memory area pointed to by s with the constant byte b
 *
 * @s: the memory area to be filled
 * @b: the constant byte value to fill the memory area with
 * @n: the number of bytes to fill in the memory area
 *
 * Return: a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{

	unsigned int index;

	for (index = 0; index < n; index++)
	{
		s[index] = b;
	}

	return (s);
}