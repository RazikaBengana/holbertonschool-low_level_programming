#include "main.h"

/**
 * main - the entry point
 *
 * program that computes and prints the sum of all the multiples of 3 or 5 below 1024 (excluded),
 * followed by a new line
 *
 * example : if we list all the natural numbers below 10 that are multiples of 3 or 5,
 *           we get 3, 5, 6 and 9;
 *           the sum of these multiples is 23
 *
 * Return: 0 (success)
 */

int main(void)
{
	int current_number, sum_of_multiples = 0;

	for (current_number = 0; current_number < 1024; current_number++)
	{
		if ((current_number % 3) == 0 || (current_number % 5) == 0)
			sum_of_multiples += current_number;
	}

	printf("%d\n", sum_of_multiples);

	return (0);
}