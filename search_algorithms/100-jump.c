#include "search_algos.h"

/**
 * jump_search - program that performs a "jump search" on a sorted array
 *
 * jump search is a searching algorithm used for finding a specific value in a sorted array;
 * the key principle of this algorithm is to jump a fixed number of steps or blocks in the array
 * instead of searching each element, thereby improving the search efficiency compared to linear search;
 * the optimal size of each jump or block is typically the square root of the array's length;
 * this method strikes a balance between a "linear search" and a "binary search" in terms of performance;
 * the algorithm works by jumping ahead by fixed steps (the square root of array length)
 * and then performing a linear search backward from the current position in the array to find the element;
 *
 * the array must be sorted for this search technique to work correctly;
 * every time we compare a value in the array to the value we are searching for, we have to print this value
 *
 * Complexity:
 * - Time complexity: O(√n), where n is the number of elements in the array
 * - Space complexity: O(1), as it requires only a constant amount of additional memory space
 *
 * @array: a pointer to the first element of the array where the search is performed
 * @size: the number of elements in the array
 * @value: the target value to search for in the array
 *
 * Return: the index at which the target value is found within the array, or -1 if the value is not found
 */

int jump_search(int *array, size_t size, int value)
{
	size_t currentIndex = 0, jumpStep = sqrt(size), previousIndex;

	if (!array)
		return (-1);

	/* Finding the block where the element is present (if it's present) */
	while (currentIndex < size && array[currentIndex] < value)
	{
		printf("Value checked array[%zu] = [%d]\n", currentIndex, array[currentIndex]);
		currentIndex += jumpStep;
	}

	/* Finding the block where the search will be conducted */
	previousIndex = currentIndex - jumpStep;
	printf("Value found between indexes [%zu] and [%zu]\n", previousIndex, currentIndex);

	/* Linear search for value in the block beginning with previousIndex */
	currentIndex = currentIndex >= size ? size - 1 : currentIndex;

	while (previousIndex <= currentIndex)
	{
		printf("Value checked array[%zu] = [%d]\n", previousIndex, array[previousIndex]);

		if (array[previousIndex] == value)
			return (previousIndex);

		previousIndex++;
	}
	return (-1);
}
