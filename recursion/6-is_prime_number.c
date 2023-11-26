#include "main.h"

/**
 * check_divisibility - program that checks if a number is divisible by any number
 *
 * @num: the number to check divisibility for
 * @divisor: the divisor to check
 *
 * Return: 1 if num is divisible by divisor, otherwise return 0
 */

int check_divisibility(int num, int divisor)
{
	if (num == divisor)
		return (1);

	else if (num % divisor == 0)
		return (0);

	return (check_divisibility(num, divisor + 1));
}


/**
 * is_prime_number - checks if a number is a prime number
 *
 * @n: the number to check
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */

int is_prime_number(int n)
{
	if (n == 1)
		return (0);

	return (check_divisibility(n, 2));
}