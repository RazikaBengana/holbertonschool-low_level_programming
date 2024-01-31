#include "search_algos.h"

/**
 * _advanced_binary - a helper function to perform a "binary search" recursively
 * on a sorted array of integers to find the first occurrence of a specific value
 *
 * this function performs a binary search on a sorted array of integers;
 * its primary goal is to find the first occurrence of a specific integer value in the array;
 * it uses recursion for searching;
 * initially, it prints the array being searched;
 * then, it calculates the middle index of the current array segment and checks if the value
 * at this index matches the target value;
 * if it matches and it's the first element, it returns the pointer to this element;
 * if the value is greater, it continues searching in the left half;
 * otherwise, in the right half;
 *
 * every time we split the array, we have to print the new array (or subarray) we’re searching in
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for in the array
 *
 * Return: a pointer to the first occurrence of the value in the array, or NULL if it's not found
 */

int *_advanced_binary(int *array, size_t size, int value)
{
	size_t middle_index = 0;

	if (!size || !array)
		return (NULL);

	for (printf("Searching in array: "); middle_index < size; middle_index++)
		printf("%d%s", array[middle_index], middle_index + 1 == size ? "\n" : ", ");

	middle_index = (size - 1) / 2;

	if (array[middle_index] == value)
	{
		if (middle_index)
			return (_advanced_binary(array, middle_index + 1, value));
		return (array + middle_index);
	}

	else if (array[middle_index] > value)
		return (_advanced_binary(array, middle_index + 1, value));

	else
		return (_advanced_binary(array + middle_index + 1, size - middle_index - 1, value));
}



/**
 * advanced_binary - program that initiates a "binary search" to find the first occurrence of a value
 * in a sorted array of integers
 *
 * this function serves as a wrapper for the _advanced_binary function;
 * it initiates the binary search process to find the first occurrence of a given value in the array;
 * it calls '_advanced_binary' and then checks the returned pointer;
 * if the pointer is NULL, it means the value was not found, and it returns -1;
 * otherwise, it calculates and returns the index of the found value within the array
 *
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for in the array
 *
 * Return: the index where the value is first found, or -1 if it's not found
 */

int advanced_binary(int *array, size_t size, int value)
{
	int *found_ptr = _advanced_binary(array, size, value);

	if (!found_ptr)
		return (-1);

	else
		return (found_ptr - array);
}