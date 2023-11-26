#include "main.h"

/**
 * argstostr - program that converts an array of strings into a single string
 *
 * this function takes an array of strings (command-line arguments) and
 * concatenates them into a single string, separating each argument with a newline;
 * it allocates memory for the resulting string and returns a pointer to it;
 * if the input arguments are invalid, the function returns NULL
 *
 * @argc: the number of arguments in the array
 * @argv: an array of strings representing the arguments
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */

char *argstostr(int argc, char **argv)
{
	char *result;
	int argIndex, charIndex, totalSize = argc;
	int currentIndex = 0;

	if (argc == 0 || argv == NULL)
		return (NULL);

/* Calculate the total size needed for the concatenated string */
	for (argIndex = 0; argIndex < argc; argIndex++)
	{
		for (charIndex = 0; argv[argIndex][charIndex]; charIndex++)
			totalSize++;
	}

/* Allocate memory for the concatenated string */
	result = (char *)malloc(sizeof(char) * (totalSize + 1));

	if (result == NULL)
		return (NULL);

/* Concatenate the strings with newlines */
	for (argIndex = 0; argIndex < argc; argIndex++)
	{
		for (charIndex = 0; argv[argIndex][charIndex]; charIndex++)
			result[currentIndex++] = argv[argIndex][charIndex];

		result[currentIndex++] = '\n';
	}

	result[totalSize] = '\0';

	return (result);
}