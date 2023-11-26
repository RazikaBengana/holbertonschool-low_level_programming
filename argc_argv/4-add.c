#include "main.h"

/**
 * main - the entry point
 *
 * program that adds positive numbers
 *
 * if no number is passed to the program, print 0, followed by a new line
 * if one of the number contains symbols that are not digits, print Error, followed by a new line, and return 1
 * we can assume that numbers and the addition of all the numbers can be stored in an int
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 if the addition is successful, 1 if an error occurs
 */

int main(int argc, char *argv[])
{
	int index;
	int number;
	int sum = 0;

	if (argc == 1)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (index = 1; index < argc; index++)
	{
		for (number = 0; argv[index][number]; number++)
		{
			if (argv[index][number] < '0' || argv[index][number] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum = sum + atoi(argv[index]);
	}

	printf("%d\n", sum);

	return (0);
}