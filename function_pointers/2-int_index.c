#include "function_pointers.h"

/**
 * int_index - program that searches for an integer
 *
 * this function takes an array of integers, its size, and a function pointer as arguments;
 * if the array, size, and function pointer are valid, it iterates over each element of the array;
 * for each element, the function pointed to by `cmp` is called to compare the value of the element
 *
 * @array: a pointer to the array of integers
 * @size: the number of elements in the array 'array'
 * @cmp: a pointer to the function to be used to compare values
 *
 * Return: the index of the first element for which the cmp function does not return 0,
 * or -1 if no element matches the comparison, or if size <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int index;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (index = 0; index < size; index++)
	{
		if (cmp(array[index]) != 0)
			return (index);
	}

	return (-1);
}