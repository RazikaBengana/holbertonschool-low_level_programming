#include "main.h"

/**
 * main - the entry point
 *
 * program that prints the number of arguments passed into it
 *
 * the program should print a number, followed by a new line
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	(void)argv; /* Unused argument (avoiding compiler warning) */

	printf("%d\n", argc - 1);

	return (0);
}