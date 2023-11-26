#include "main.h"

/**
 * _calloc - program that allocates memory for an array, using malloc
 *
 * the _calloc function allocates memory for an array of nmemb elements of size bytes each,
 * and returns a pointer to the allocated memory;
 * the memory is set to zero
 *
 * if nmemb or size is 0, then _calloc returns NULL
 * if malloc fails, then _calloc returns NULL
 *
 * @nmemb: the number of elements in the array
 * @size: the size of each element in bytes
 *
 * Return: a pointer to the allocated memory, or NULL if it fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *array;
	unsigned int index;

	if (size == 0 || nmemb == 0)
		return (NULL);

	array = malloc(size * nmemb);

	if (array == NULL)
		return (NULL);

	for (index = 0; index < (size * nmemb); index++)
		array[index] = 0;

	return (array);
}