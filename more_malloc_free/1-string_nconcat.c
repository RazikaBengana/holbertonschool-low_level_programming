#include "main.h"

/**
 * string_nconcat - program that concatenates two strings
 *
 * the  returned pointer shall point to a newly allocated space in memory,
 * which contains s1, followed by the first n bytes of s2, and null terminated
 * if n is greater or equal to the length of s2, then we have to use the entire string s2
 * if NULL is passed, we have to treat it as an empty string
 *
 * @s1: the 1st string
 * @s2: the 2nd string
 * @n: the number of bytes from s2 to concatenate
 *
 * Return: a pointer to the concatenated string, or NULL if it fails
 *
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concatenated;
	unsigned int len_s1, len_s2, index1, index2;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (len_s1 = 0; s1[len_s1] != '\0'; len_s1++)
		;

	for (len_s2 = 0; s2[len_s2] != '\0'; len_s2++)
		;

	if (n > len_s2)
		n = len_s2;

	index2 = len_s1 + n;

	concatenated = malloc(sizeof(char) * (index2 + 1));

	if (concatenated == NULL)
	{
		free(concatenated);
		return (NULL);
	}

	for (index1 = 0; index1 < index2; index1++)
	{
		if (index1 < len_s1)
			concatenated[index1] = s1[index1];
		else
			concatenated[index1] = s2[index1 - len_s1];
	}

	concatenated[index2] = '\0';

	return (concatenated);
}