#include "main.h"

/**
 * swap_int - program that swaps the values of two integers
 *
 * @a: the 1st integer to swap
 * @b: the 2nd integer to swap
 *
 * Return: nothing (void)
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}