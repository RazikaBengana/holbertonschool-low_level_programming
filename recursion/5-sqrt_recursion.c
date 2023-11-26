#include "main.h"

/**
 * findSquareRoot - recursive helper function that calculates the square root
 * of a number using a simple recursive approach
 *
 * @n: the number for which the square root is calculated
 * @estimatedSquareRoot: the current value being tested as the square root
 *
 * Return: the natural square root of the number if it is a perfect square,
 * or -1 if n does not have a natural square root
 */

int findSquareRoot(int n, int estimatedSquareRoot)
{
	if (estimatedSquareRoot * estimatedSquareRoot == n)
		return (estimatedSquareRoot);

	else if (estimatedSquareRoot * estimatedSquareRoot > n)
		return (-1);

	return (findSquareRoot(n, estimatedSquareRoot + 1));
}


/**
 * _sqrt_recursion - program that returns the natural square root of a number
 *
 * @n: the number for which the square root is calculated
 *
 * Return: the natural square root of the number if it is a perfect square,
 * or -1 if n does not have a natural square root
 */

int _sqrt_recursion(int n)
{
	return (findSquareRoot(n, 1));
}