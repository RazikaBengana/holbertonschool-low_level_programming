#include "search_algos.h"

/**
 * interpolation_search - program that performs an "interpolation search" on a sorted array
 * to find the index of a target value
 *
 * this search algorithm is an improvement over "binary search" when dealing with uniformly distributed values;
 * it works by estimating the position of the target value using the formula for linear interpolation;
 * so, this function assumes that the array is sorted and the values are uniformly distributed;
 *
 * to determine the probe position, we can use:
 * size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]))
 *
 * every time we compare a value in the array to the value we are searching, we have to print this value

 * @array: the array of integers to be searched
 * @size: the number of elements in the array
 * @value: the target value to be found in the array
 *
 * Return: the index of the target value if found, otherwise -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t position = 0, lower_bound = 0, upper_bound = size - 1;

	if (!array || !size)
		return (-1);

	while (1)
	{
		position = lower_bound + (((double)(upper_bound - lower_bound) /
					   (array[upper_bound] - array[lower_bound])) * (value - array[lower_bound]));

		if (position >= size)
		{
			printf("Value checked array[%zu] is out of range\n", position);
			break;
		}
		printf("Value checked array[%zu] = [%d]\n", position, array[position]);

		if (array[position] == value)
			return (position);

		else if (array[position] > value)
			upper_bound = position - 1;

		else
			lower_bound = position + 1;
	}
	return (-1);
}
