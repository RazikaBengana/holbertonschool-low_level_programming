#include "main.h"

/**
 * print_buffer - program that prints the content of a buffer in a formatted and readable way
 *
 * the function must print the content of size bytes of the buffer pointed by 'buffer';
 * the output should print 10 bytes per line;
 * each line starts with the position of the first byte of the line in hexadecimal (8 chars), starting with 0;
 * each line shows the hexadecimal content (2 chars) of the buffer, 2 bytes at a time, separated by a space;
 * each line shows the content of the buffer;
 * if the byte is a printable character, print the letter, if not, print ".";
 * each line ends with a new line \n;
 * if size is 0 or less, the output should be a new line, only \n
 *
 * @buffer: a pointer to the buffer containing the data to be printed
 * @size: the size of the buffer in bytes
 *
 * Return: nothing (void)
 */

void print_buffer(char *buffer, int size)
{
	int byteOffset, index;

	for (byteOffset = 0; byteOffset < size; byteOffset += 10)
	{
		printf("%08x: ", byteOffset);

		for (index = 0; index < 10; index++)
		{
			if ((index + byteOffset) >= size)
				printf("  ");
			else
				printf("%02x", *(buffer + index + byteOffset));

			if ((index % 2) != 0 && index != 0)
				printf(" ");
		}

		for (index = 0; index < 10; index++)
		{
			if ((index + byteOffset) >= size)
				break;
			else if (*(buffer + index + byteOffset) >= 31 &&
				 *(buffer + index + byteOffset) <= 126)
				printf("%c", *(buffer + index + byteOffset));
			else
				printf(".");
		}

		if (byteOffset >= size)
			continue;

		printf("\n");
	}

	if (size <= 0)
		printf("\n");
}