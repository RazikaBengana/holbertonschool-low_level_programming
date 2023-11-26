#include <stdio.h>

/**
 * main - the entry point
 *
 * program that prints all possible combinations of two two-digit numbers
 *
 * the two numbers should be separated by a space
 * all numbers should be printed with two digits ---> 1 should be printed as 01
 * the combination of numbers must be separated by comma, followed by a space
 * the combinations of numbers should be printed in ascending order
 * 00 01 and 01 00 are considered as the same combination of the numbers 0 and 1
 *
 * Return: 0 (success)
 */

int main(void)
{
	int tens_digit_first_num, ones_digit_first_num;
	int tens_digit_second_num, ones_digit_second_num;

	for (tens_digit_first_num = 0; tens_digit_first_num <= 98; tens_digit_first_num++)
	{
		for (tens_digit_second_num = tens_digit_first_num + 1; tens_digit_second_num <= 99; tens_digit_second_num++)
		{
			ones_digit_first_num = tens_digit_first_num % 10;
			ones_digit_second_num = tens_digit_second_num % 10;

			putchar((tens_digit_first_num / 10) + '0');
			putchar(ones_digit_first_num + '0');
			putchar(' ');
			putchar((tens_digit_second_num / 10) + '0');
			putchar(ones_digit_second_num + '0');

			if (tens_digit_first_num == 98 && tens_digit_second_num == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}