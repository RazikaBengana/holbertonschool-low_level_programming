#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all possible different combinations of two digits
 *
 * numbers must be separated by a comma, followed by a space
 * the two digits must be different
 * 01 and 10 are considered the same combination of the two digits 0 and 1
 * we print only the smallest combination of two digits
 * numbers should be printed in ascending order, with two digits
 *
 * Return: 0 (success)
 */

int main(void)
{
	int first_digit, second_digit;

	for (first_digit = '0'; first_digit < '9'; first_digit++)
	{
		for (second_digit = first_digit + 1; second_digit <= '9'; second_digit++)
		{
			if (second_digit != first_digit)
			{
				putchar(first_digit);
				putchar(second_digit);

				if (first_digit == '8' && second_digit == '9')
					continue;

				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}