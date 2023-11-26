#include "main.h"

/**
 * array_range - program that creates an array of integers
 *
 * the array created should contain all the values from min (included) to max (included),
 * ordered from min to max
 *
 * if min > max, return NULL
 *
 * @min: the minimum value of the range (inclusive)
 * @max: the maximum value of the range (inclusive)
 *
 * Return: the pointer to the newly created array, or NULL if malloc fails
 */

int *array_range(int min, int max)
{
	int *array, size, index;

	if (min > max)
		return (NULL);

	size = (max - min) + 1;

	array = malloc(sizeof(int) * size);

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		array[index] = min;
		min++;
	}

	return (array);
}