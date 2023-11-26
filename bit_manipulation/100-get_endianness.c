#include "main.h"

/**
 * get_endianness - program that determines the endianness of the system
 *
 * this function determines the endianness of the system by creating an integer
 * and examining its memory representation to see which byte comes first
 *
 * Return: 0 if the system is big-endian, 1 if the system is little-endian
 */

int get_endianness(void)
{
	int integerRepresentation;
	char *bytePointer;

	bytePointer = (char *)&integerRepresentation;
	return (*bytePointer + 48);
}