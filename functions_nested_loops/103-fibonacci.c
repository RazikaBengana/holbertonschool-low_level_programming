#include "main.h"

/**
 * main - the entry point
 *
 * program that finds and prints the sum of the even-valued terms, followed by a new line
 *
 * This function calculates the sum of even-valued terms in the Fibonacci
 * sequence whose values do not exceed 4000000;
 * It uses a loop to generate Fibonacci numbers and accumulates the sum of
 * even numbers along the way
 *
 * Return: 0 (success)
 */

int main(void)
{
	unsigned long previous_term = 0, current_term = 1, next_term;
	float even_sum = 0;

	while (1)
	{
		next_term = previous_term + current_term;
		if (next_term > 4000000)
			break;

		if ((next_term % 2) == 0)
			even_sum += next_term;

		previous_term = current_term;
		current_term = next_term;
	}

	printf("%.0f\n", even_sum);

	return (0);
}