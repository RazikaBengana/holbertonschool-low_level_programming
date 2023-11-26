#include "main.h"

/**
 * str_concat - program that concatenates two strings
 *
 * the returned pointer should point to a newly allocated space in memory which contains the contents of s1,
 * followed by the contents of s2, and null terminated
 * if NULL is passed, we have to treat it as an empty string
 *
 * @s1: the 1st string
 * @s2: the 2nd string
 *
 * Return: a pointer to the concatenated string, or NULL if it fails
 */

char *str_concat(char *s1, char *s2)
{

	char *concatenated;
	int length;
	int index;
	int s1_length = 0, s2_length = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (s1_length = 0; s1[s1_length]; s1_length++)
		;
	for (s2_length = 0; s2[s2_length]; s2_length++)
		;

	length = s1_length + s2_length;

	concatenated = malloc(sizeof(char) * (length + 1));

	if (concatenated == NULL)
	{
		free(concatenated);
		return (NULL);
	}

	for (index = 0; index < s1_length; index++)
		concatenated[index] = s1[index];

	for (index = 0; index < s2_length; index++)
		concatenated[s1_length + index] = s2[index];

	concatenated[length] = '\0';

	return (concatenated);
}