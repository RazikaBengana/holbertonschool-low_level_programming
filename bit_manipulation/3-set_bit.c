#include "main.h"

/**
 * set_bit - program that sets the value of a bit to 1 at a given index
 * (in an unsigned long integer)
 *
 * @index: the index, starting from 0 of the bit we want to set
 * @n: a pointer to the unsigned long integer in which to set the bit
 *
 * Return: 1 if successful, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(index) * 8))
		return (-1);

	*n |= 1 << index;

	return (1);
}