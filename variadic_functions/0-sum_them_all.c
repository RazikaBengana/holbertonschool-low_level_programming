#include "variadic_functions.h"

/**
 * sum_them_all - program that returns the sum of all its parameters
 *
 * @n: the number of arguments
 * @...: a variable number of integer arguments to be summed
 *
 * Return: the sum of all the arguments, or 0 if n == 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int arg_index;

	va_list args;

	va_start(args, n);

	for (arg_index = 0; arg_index < n; arg_index++)
	{
		sum += va_arg(args, int);
	}

	va_end(args);

	return (sum);
}