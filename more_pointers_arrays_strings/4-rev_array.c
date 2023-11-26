#include "main.h"

/**
 * reverse_array - program that reverses the content of an array of integers
 *
 * @a: the array to be reversed
 * @n: the number of array's elements
 *
 * Return: nothing (void)
 */

void reverse_array(int *a, int n)
{
	int index, temp;

	for (index = 0; index < n / 2; index++)
	{
		temp = a[index];
		a[index] = a[n - 1 - index];
		a[n - 1 - index] = temp;
	}
}