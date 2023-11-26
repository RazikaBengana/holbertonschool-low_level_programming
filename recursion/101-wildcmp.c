#include "main.h"

/**
 * wildcmp - program that compares two strings with wildcards
 *
 * this function compares two strings, s1 and s2, taking into account wildcard characters;
 * the wildcard '*' can match any sequence of characters (including an empty sequence) in s1;
 * the function uses a recursive approach to determine if s1 matches s2 with wildcard patterns
 *
 * @s1: the first string to compare
 * @s2: the second string to compare
 *
 * Return: 1 if the strings can be considered identical (if they match with wildcard patterns),
 * otherwise 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
			return (1);
	}

	return (0);
}