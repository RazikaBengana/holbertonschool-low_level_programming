#include "main.h"

/**
 * factorial - program that returns the factorial of a given number
 *
 * @n: the number to calculate the factorial of
 *
 * Return: the factorial of a given number, or -1 to indicate an error, if n is lower than 0
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	else if (n == 0)
	{
		return (1);
	}

	return (n * factorial(n - 1));
}