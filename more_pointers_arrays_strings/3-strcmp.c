#include "main.h"

/**
 * _strcmp - program that compares two strings
 *
 * the function calculates and returns the difference between the ASCII values
 * of the characters pointed to by s1 and s2
 *
 * @s1: the 1st string to compare
 * @s2: the 2nd string to compare
 *
 * Return: an integer value that indicates the lexicographic comparison between the two input strings
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}