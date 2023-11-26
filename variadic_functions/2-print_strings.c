#include "variadic_functions.h"

/**
 * print_strings - program that prints strings separated by a given separator, and followed by a new line
 *
 * if one of the string is NULL, we have to print (nil) instead
 *
 * @separator: the string separator to be printed between strings (or NULL if no separator is needed)
 * @n: the number of string arguments passed to the function
 * @...: a variable number of string arguments to be printed
 *
 * Return: nothing (void)
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int arg_index;
	va_list args;
	char *str;

	va_start(args, n);

	for (arg_index = 0; arg_index < n; arg_index++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && (arg_index + 1) != n)
			printf("%s", separator);
	}
	printf("\n");

	va_end(args);
}