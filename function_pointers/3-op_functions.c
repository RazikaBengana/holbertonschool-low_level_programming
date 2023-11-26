#include "3-calc.h"

/**
 * op_add - program that returns the sum of 2 integers
 *
 * @a: the 1st integer
 * @b: the 2nd integer
 *
 * Return: the sum of a and b
 */

int op_add(int a, int b)
{
	return (a + b);
}


/**
 * op_sub - program that returns the difference between two integers
 *
 * @a: the 1st integer
 * @b: the 2nd integer
 *
 * Return: the difference between a and b
 */

int op_sub(int a, int b)
{
	return (a - b);
}


/**
 * op_mul - program that returns the product of two integers
 *
 * @a: the 1st integer
 * @b: the 2nd integer
 *
 * Return: the product of a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}


/**
 * op_div - program that returns the result of dividing two integers
 *
 * if the user tries to divide (/ or %) by 0, we have to print Error,
 * followed by a new line, and exit with the status 100
 *
 * @a: the dividend
 * @b: the divisor
 *
 * Return: the result of dividing a by b
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}


/**
 * op_mod - program that returns the remainder of dividing two integers (the modulo)
 *
 * if the user tries to divide (/ or %) by 0, we have to print Error,
 * followed by a new line, and exit with the status 100
 *
 * @a: the dividend
 * @b: the divisor
 *
 * Return: the remainder of dividing a by b (the modulo)
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}