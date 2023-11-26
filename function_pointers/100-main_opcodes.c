#include "function_pointers.h"

/**
 * print_bytes_from_address - program that prints hexadecimal representation
 * of bytes from a memory address
 *
 * @address: the pointer to the memory address to print bytes from
 * @num_bytes: the number of bytes to print
 *
 * this function takes a memory address and a number of bytes to print;
 * it prints the hexadecimal representation of the bytes at the given address;
 * It prints the bytes in a formatted manner;
 *
 * Return: nothing (void)
 */

void print_bytes_from_address(void *address, int num_bytes)
{
	char *bytePtr = (char *)address;
	int i;

	for (i = 0; i < num_bytes - 1; i++)
	{
		printf("%02hhx ", bytePtr[i]);
	}

	printf("%02hhx\n", bytePtr[num_bytes - 1]);
}


/**
 * main - the entry point
 *
 * program that prints the opcodes of its own main function
 *
 * the opcodes should be printed in hexadecimal, lowercase;
 * each opcode is two char long;
 * listing ends with a new line;
 *
 * we do not have to compile with any flags
 *
 * @argc: the number of command-line arguments
 * @argv: the array of command-line argument strings
 *
 * Return: 0 if successful, 1 if argc is not 2,
 * 2 if the provided byte count is negative
 */

int main(int argc, char *argv[])
{
	char *mainAddress;
	int i, numBytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	numBytes = atoi(argv[1]);

	if ((numBytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	mainAddress = (char *)&main;
	print_bytes_from_address(mainAddress, numBytes);

	return (0);
}