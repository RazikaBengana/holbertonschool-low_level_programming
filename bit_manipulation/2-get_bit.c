#include "main.h"

/**
 * get_bit - program that returns the value of a bit at a given index
 *
 * we have to get the value of a specific bit in a given number
 *
 * @n: the unsigned long integer from which to extract the bit
 * @index: the index, starting from 0 of the bit we want to get
 *
 * Return: the value of the bit at the specified index, or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(index) * 8))
		return (-1);

	if ((n >> index) & 1)
		return (1);
	return (0);
}