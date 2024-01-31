#include "search_algos.h"

/**
 * linear_search - program that performs a "linear search" on an array of integers
 *
 * this function sequentially checks each element of an integer array to find a given value;
 *
 * every time we compare a value in the array to the value we are searching,
 * we have to print this value
 *
 * @array: a pointer to the first element of the integer array to be searched
 * @size: the number of elements in the array
 * @value: the integer value to search for in the array
 *
 * Return: the index of the first occurrence of the value in the array,
 * 	   or -1 if not found or the array is NULL
 */

int linear_search(int *array, size_t size, int value)
{
	size_t index;

	if (array == NULL || value == '\0')
		return (-1);

	for (index = 0; index < size; index++)
	{
		printf("Value checked array[%zu] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
	}
	return (-1);
}
