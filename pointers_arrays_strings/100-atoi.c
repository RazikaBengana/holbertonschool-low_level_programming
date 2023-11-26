#include "main.h"

/**
 * _atoi - program that converts a string to an integer
 *
 * the number in the string can be preceded by an infinite number of characters
 * we need to take into account all the - and + signs before the number
 * if there are no numbers in the string, the function must return 0
 * we have to use the -fsanitize=signed-integer-overflow gcc flag to compile the code
 *
 * @str: the string to be converted
 *
 * Return: the converted integer value, or 0 if there are no numbers in the string
 */

int _atoi(char *str)
{
	int sign = 1;
	unsigned int result = 0;

	do {
		if (*str == '-')
			sign *= -1;

		else if (*str >= '0' && *str <= '9')
			result = (result * 10) + (*str - '0');

		else if (result > 0)
			break;

	} while (*str++);

	return (result * sign);
}