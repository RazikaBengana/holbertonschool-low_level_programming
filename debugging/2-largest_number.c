#include "main.h"

/**
 * largest_number - program that returns the largest of 3 numbers
 *
 * we have to fix the code so that it correctly prints out the largest of three numbers
 *
 * @a: first integer
 * @b: second integer
 * @c: third integer
 *
 * Return: the largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

	if (a >= b && a > c)
	{
		largest = a;
	}

	else if (b >= a && b > c)
	{
		largest = b;
	}

	else
	{
		largest = c;
	}

	return (largest);
}