#include "main.h"

/**
 * main - the entry point
 *
 * program that prints its name, followed by a new line
 *
 * if we rename the program, it will print the new name, without having to compile it again
 * we should not remove the path before the name of the program
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	(void)argc; /* Unused argument (avoiding compiler warning) */

	printf("%s\n", argv[0]);

	return (0);
}