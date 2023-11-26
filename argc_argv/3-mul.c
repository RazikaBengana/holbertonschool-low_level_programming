#include "main.h"

/**
 * main - the entry point
 *
 * program that multiplies two numbers
 *
 * the program should print the result of the multiplication, followed by a new line
 * we can assume that the two numbers and result of the multiplication can be stored in an integer
 * if the program does not receive two arguments, it should print Error, followed by a new line, and return 1
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 if the multiplication is successful, or 1 if an error occurs
 */

int main(int argc, char *argv[])
{
	int index, product = 1;

	if (argc >= 3)
	{
		for (index = 1; index < argc; index++)
		{

			product = product * atoi(argv[index]);
		}

		printf("%d\n", product);

		return (0);
	}

	else
	{
		printf("Error\n");

		return (1);
	}
}