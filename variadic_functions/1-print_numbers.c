#include "variadic_functions.h"

/**
 * print_numbers - program that prints a sequence of numbers separated by a given separator,
 * and followed by a new line
 *
 * @separator: the string separator to be printed between numbers (or NULL if no separator is needed)
 * @n: the number of integer arguments passed to the function
 * @...: a variable number of integer arguments to be printed
 *
 * Return: nothing (void)
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int arg_index;
	va_list args;

	va_start(args, n);

	for (arg_index = 0; arg_index < n; arg_index++)
	{
		printf("%d", va_arg(args, int));

		if (separator != NULL && arg_index < n - 1)
		{
			printf("%s", separator);
		}
	}
	printf("\n");

	va_end(args);
}