#include "main.h"

/**
 * main - the entry point
 *
 * program that prints the first 50 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line
 *
 * the numbers must be separated by comma, followed by a space ---> ", "
 *
 * Return: 0 (success)
 */

int main(void)
{
	int iteration;
	unsigned long currentFibonacci = 0, nextFibonacci = 1, sum;

	for (iteration = 0; iteration < 50; iteration++)
	{
		sum = currentFibonacci + nextFibonacci;
		printf("%lu", sum);

		currentFibonacci = nextFibonacci;
		nextFibonacci = sum;

		if (iteration == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}