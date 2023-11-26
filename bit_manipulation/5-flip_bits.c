#include "main.h"

/**
 * flip_bits - program that returns the number of bits you would need to flip
 * to get from one number to another
 *
 * this function calculates the number of different flipped bits
 * between two unsigned long integers
 *
 * @n: the first unsigned long integer
 * @m: The second unsigned long integer
 *
 * Return: the count of different bits between num1 and num2
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int different_bits_count = 0;

	while (xor_result > 0)
	{
		if ((xor_result & 1) != 0)
			different_bits_count++;

		xor_result = xor_result >> 1;
	}

	return (different_bits_count);
}