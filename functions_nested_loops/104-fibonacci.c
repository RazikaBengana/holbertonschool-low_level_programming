#include "main.h"

/**
 * main - the entry point
 *
 * program that finds and prints the first 98 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line
 *
 * the numbers should be separated by comma, followed by a space ---> ", "
 *
 * Return: 0 (success)
 */

int main(void)
{
	int iteration;
	unsigned long previousFibonacci = 0, currentFibonacci = 1, newFibonacci;
	unsigned long currentFibHalf1, currentFibHalf2, nextFibHalf1, nextFibHalf2;
	unsigned long resultHalf1, resultHalf2;

	for (iteration = 0; iteration < 92; iteration++)
	{
		newFib = currentFib + nextFib;
		printf("%lu, ", newFib);

		currentFib = nextFib;
		nextFib = newFib;
	}

	currentFibHalf1 = currentFib / 10000000000;
	nextFibHalf1 = nextFib / 10000000000;
	currentFibHalf2 = currentFib % 10000000000;
	nextFibHalf2 = nextFib % 10000000000;

	for (iteration = 93; iteration < 99; iteration++)
	{
		resultHalf1 = currentFibHalf1 + nextFibHalf1;
		resultHalf2 = currentFibHalf2 + nextFibHalf2;

		if (currentFibHalf2 + nextFibHalf2 > 9999999999)
		{
			resultHalf1 += 1;
			resultHalf2 %= 10000000000;
		}

		printf("%lu%lu", resultHalf1, resultHalf2);

		if (iteration != 98)
			printf(", ");

		currentFibHalf1 = nextFibHalf1;
		currentFibHalf2 = nextFibHalf2;
		nextFibHalf1 = resultHalf1;
		nextFibHalf2 = resultHalf2;
	}

	printf("\n");

	return (0);
}