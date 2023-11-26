#include "variadic_functions.h"

/**
 * print_all - program that prints anything, followed by a new line
 *
 * this function prints a sequence of characters, integers, floats, and strings based on a format string
 *
 * @format: a pointer to a format string containing the list of types of arguments passed to the function;
 *
 * the format string can include the following conversion specifiers:
 * - 'c': a character
 * - 'i': an integer
 * - 'f': a float
 * - 's': a string (char pointer ---> char *). If the string is NULL, print (nil) instead
 *
 * any other char should be ignored
 *
 * Return: nothing (void)
 */

void print_all(const char * const format, ...)
{
	int index = 0;
	char *str;
	va_list args;

	va_start(args, format);

	while (format && format[index])
	{
		switch (format[index++])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%i", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				continue;
		}

		if (format[index])
		{
			printf(", ");
		}
	}
	putchar('\n');

	va_end(args);
}