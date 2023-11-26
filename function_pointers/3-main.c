#include "3-calc.h"

/**
 * main - the entry point
 *
 * program that performs simple arithmetic operations
 *
 * the program prints the result of the operation, followed by a new line
 * we can assume num1 and num2 are integers, so we have to use the atoi function to convert them from the string input to int
 *
 * if the number of arguments is wrong, we have to print Error, followed by a new line, and exit with the status 98
 * if the operator is none of the above, we have to print Error, followed by a new line, and exit with the status 99
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 if successful, otherwise exits with an error code
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operation = get_op_func(argv[2]);

	if (operation  == NULL || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	result = operation(num1, num2);
	printf("%d\n", result);

	return (0);
}