#include "search_algos.h"

/**
 * binary_search - program that executes a "binary search" on an array of integers
 *
 * this function implements a binary search algorithm to find a specific value in a sorted array of integers;
 * the binary search is efficient as it halves the search range in each step;
 * it compares the middle element of the array to the target value;
 * if the target matches the middle element, the function returns its index;
 * if the target is less than the middle element, the search continues in the left half of the array;
 * if greater, in the right half;
 * this process is repeated until the value is found or the range is empty;
 * the function also prints the currently searched subarray for visualization;
 *
 * the array should be sorted in ascending order
 *
 * @array: a pointer to the first element of the array
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the index of the value if found, otherwise -1 if array is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	size_t leftIndex = 0, midIndex = 0, rightIndex = size - 1;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	while (leftIndex <= rightIndex)
	{
		printf("Searching in array: ");

		for (i = leftIndex; i <= rightIndex; i++)
		{
			if (i < rightIndex)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}

		midIndex = (leftIndex + rightIndex) / 2;

		if (array[midIndex] < value)
			leftIndex = midIndex + 1;

		else if (array[midIndex] > value)
			rightIndex = midIndex - 1;

		else
			return (midIndex);
	}
	return (-1);
}
