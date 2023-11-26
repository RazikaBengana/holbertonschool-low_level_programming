#include "main.h"

/**
 * clear_bit - program that sets the value of a bit to 0 at a given index
 *
 * this function clears a specific bit at a given index
 * in an unsigned long integer
 *
 * @index: the index, starting from 0 of the bit we want to set (to be cleared)
 * @n: a pointer to the number whose bit needs to be cleared
 *
 * Return: 1 if successful, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index > (sizeof(index) * 8))
		return (-1);

	*n = *n & ~(1 << index);

	return (1);
}