#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all possible different combinations of three digits
 *
 * numbers must be separated by a comma, followed by a space
 * the three digits must be different
 * 012, 120, 102, 021, 201, 210 are considered the same combination of the three digits 0, 1 and 2
 * we print only the smallest combination of three digits
 * numbers should be printed in ascending order, with three digits
 *
 * Return: 0 (success)
 */

int main(void)
{
	int first_digit, second_digit, third_digit;

	for (first_digit = '0'; first_digit < '9'; first_digit++)
	{
		for (second_digit = first_digit + 1; second_digit <= '9'; second_digit++)
		{
			for (third_digit = second_digit + 1; third_digit <= '9'; third_digit++)
			{
				if ((second_digit != first_digit) != third_digit)
				{
					putchar(first_digit);
					putchar(second_digit);
					putchar(third_digit);

					if (first_digit == '7' && second_digit == '8')
						continue;

					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}