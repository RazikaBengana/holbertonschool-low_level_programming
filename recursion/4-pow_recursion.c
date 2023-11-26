#include "main.h"

/**
 * _pow_recursion - program that returns the value of x raised to the power of y
 *
 * @x: the base integer
 * @y: the exponent integer
 *
 * Return: the result of x raised to the power of y, or -1 if y is lower than 0
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	else if (y == 0)
		return (1);

	else
		return (x * _pow_recursion(x, y - 1));
}