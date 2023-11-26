#include "main.h"

/**
 * main - the entry point
 *
 * program that prints all arguments it receives
 *
 * all arguments should be printed, including the first one
 * we have to print one argument per line, ending with a new line
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int index;

	for (index = 0; index < argc; index++)

		printf("%s\n", argv[index]);

	return (0);
}