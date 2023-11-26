#include "main.h"

/**
 * _strcpy - program that copies the string pointed to by src, including
 * the terminating null byte (\0), to the buffer pointed to by dest
 *
 * @src: the string source
 * @dest: the buffer that will receive the char variables of the string
 *
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char  *n = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (n);
}