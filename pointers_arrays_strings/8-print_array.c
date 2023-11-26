#include "main.h"

/**
 * print_array - program that prints n elements of an array of integers, followed by a new line
 *
 * numbers must be separated by comma, followed by a space
 * numbers should be displayed in the same order as they are stored in the array
 *
 * @a: the array
 * @n: the number of array's elements to be printed
 *
 * Return: nothing (void)
 */

void print_array(int *a, int n)
{
	int index;

	for (index = 0; index < n; index++)
	{
		printf("%d", a[index]);

		if (index < n - 1)
		{
			printf(", ");
		}
	}

	printf("\n");
}