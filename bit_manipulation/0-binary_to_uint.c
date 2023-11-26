#include "main.h"

/**
 * binary_to_uint - program that converts a binary number to an unsigned integer
 *
 * @b: a null-terminated string representing a binary number;
 * b is pointing to a string of 0 and 1 chars
 *
 * Return: the converted number (the equivalent unsigned integer value of the binary string),
 * or 0 if: - there is one or more chars in the string b that is not 0 or 1
 *          - b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int index = 0, bit_index;
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (b[index] != '\0')
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);
		index++;
	}

	for (bit_index = 0; b[bit_index] != '\0'; bit_index++)
	{
		result = result << 1;

		if (b[bit_index] == '1')
			result = result + 1;
	}

	return (result);
}