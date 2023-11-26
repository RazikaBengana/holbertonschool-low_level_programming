#include "main.h"

/**
 * create_array - program that creates an array of chars, and initializes it with a specific char
 *
 * this program returns NULL if size = 0
 *
 * @size: the size of the array
 * @c: the character to initialize the array with
 *
 * Return: a pointer to the array, or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	unsigned int index = 0;
	char *array;

	array = (char *) malloc(size * sizeof(char));

	if (size == 0)
		return (NULL);

	if (array == 0)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		array[index] = c;
	}

	return (array);
}