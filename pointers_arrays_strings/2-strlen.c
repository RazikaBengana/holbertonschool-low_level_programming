#include "main.h"

/**
 * _strlen - program that returns the length of a string
 *
 * @s: the string to be measured
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}