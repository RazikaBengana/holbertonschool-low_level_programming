#include "main.h"

/**
 * main - the entry point
 *
 * program that finds and prints the largest prime factor of the number 612852475143,
 * followed by a new line
 *
 * the program will be compiled with this command:
 * gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-prime_factor.c -o 100-prime_factor -lm
 *
 * Return: 0 (success)
 */

int main(void)
{
	long long number, prime_factor;

	number = 612852475143;

	for (prime_factor = 2; prime_factor <= number; prime_factor++)
	{
		if (number % prime_factor == 0)
		{
			number /= prime_factor;
			prime_factor--;
		}
	}

	printf("%lld\n", prime_factor);

	return (0);
}