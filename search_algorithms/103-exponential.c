#include "search_algos.h"

/**
 * exponential_search - program that performs an "exponential search" on a sorted array
 * to find a specific value
 *
 * this algorithm is particularly efficient for large datasets as it quickly
 * narrows down the search range by doubling the bound size in each iteration;
 * once the bound is determined where the element could be, it performs a binary
 * search in that sub-array;
 *
 * we have to use powers of 2 as exponential ranges to search in our array;
 * every time we compare a value in the array to the value we are searching for, we have to print this value;
 * once we’ve found the good range, we need to use a binary search:
 * every time we split the array, we have to print the new array (or subarray) we’re searching in
 *
 * @array: a pointer to the first element of the sorted array to search in
 * @size: the number of elements in the array
 * @value: the value to search for in the array
 *
 * Return: the index where value is located, or -1 if the value is not found or the array is NULL or empty
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, range_size = 0;
	int binary_search_result;

	if (!array || !size)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%zu] = [%d]\n", bound, array[bound]);
		bound <<= 1;
	}

	range_size = (bound >= size ? size : bound + 1) - (bound >> 1);
	bound >>= 1;
	printf("Value found between indexes [%zu] and [%zu]\n",
	       bound, bound << 1 >= size ? size - 1 : bound << 1);
	binary_search_result = _binary_search(array + bound, range_size, value);

	return (binary_search_result == -1 ? binary_search_result : binary_search_result + (int)bound);
}



/**
 * _binary_search - program that performs a "binary search" on a sorted sub-array
 *
 * it is typically called from other search algorithms like the exponential search function;
 * the binary search divides the array into halves in each iteration, comparing the target
 * value with the middle element;
 * depending on the comparison result, it either continues the search in the left half
 * or the right half of the array
 *
 * @array: a pointer to the first element of the sub-array to search in
 * @size: the number of elements in the sub-array
 * @value: the value to search for in the sub-array
 *
 * Return: the relative index within the sub-array where value is located,
 *         or -1 if the value is not found or the array pointer is NULL;
 *         the index is relative to the start of the sub-array, not the original array
 */

int _binary_search(int *array, size_t size, int value)
{
	size_t mid = 0;
	int *current_array = array;

	if (!array)
		return (-1);

	while (size)
	{
		for (mid = 0, printf("Searching in array: "); mid < size; mid++)
			printf("%d%s", current_array[mid], mid + 1 == size ? "\n" : ", ");

		mid = (size - 1) / 2;
		if (current_array[mid] == value)
			return ((current_array - array) + mid);

		else if (current_array[mid] > value)
			size = mid;
		else
		{
			current_array += (mid + 1);
			size -= (mid + 1);
		}
	}
	return (-1);
}