#include "main.h"

/**
 * _strdup - program that returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * the _strdup function returns a pointer to a new string which is a duplicate of the string str;
 * memory for the new string is obtained with malloc, and can be freed with free
 *
 * we have to return NULL if str = NULL
 * on success, the _strdup function returns a pointer to the duplicated string;
 * it returns NULL if insufficient memory was available
 *
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if it fails
 */

char *_strdup(char *str)
{
	char *duplicate;
	int duplicate, index;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;
	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate == NULL)
	{
		free(duplicate);
		return (NULL);
	}

	for (index = 0; index < length; index++)
		duplicate[index] = str[index];

	duplicate[length + 1] = '\0';

	return (duplicate);
}