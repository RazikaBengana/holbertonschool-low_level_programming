#include "main.h"

/**
 * main - the entry point
 *
 * program that prints the numbers from 1 to 100, followed by a new line
 *
 * for multiples of three, print Fizz instead of the number
 * for multiples of five, print Buzz
 * for numbers which are multiples of both three and five, print FizzBuzz
 * each number or word should be separated by a space
 *
 * Return: nothing (void)
 */

int main(void)
{
	int number;

	for (number = 1; number <= 100; number++)
	{
		if ((number % 3 == 0) && (number % 5 == 0))
			printf("FizzBuzz");

		else if (number % 5 == 0)
			printf("Buzz");

		else if (number % 3 == 0)
			printf("Fizz");

		else
			printf("%i", number);

		if (number < 100)
			printf(" ");

		else
			printf("\n");
	}

	return (0);
}