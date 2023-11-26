#include "main.h"

/**
 * print_to_98 - program that prints all natural numbers from n to 98, followed by a new line
 *
 * numbers must be separated by a comma, followed by a space
 * numbers should be printed in order
 * the first printed number should be the number passed to the function
 * the last printed number should be 98
 *
 * @n: the natural number to print
 *
 * Return: nothing (void)
 */

void print_to_98(int n)
{
	if (n <= 98)
		for (; n <= 97; n++)
			printf("%d, ", n);

	else
		for (; n > 98; n--)
			printf("%d, ", n);
	printf("98\n");
}