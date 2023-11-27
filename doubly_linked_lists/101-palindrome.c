#include "lists.h"


int isPalindrome(int num);
int countDigits(int value);
int power(int base, int exponent);


/**
 * main - the entry point
 *
 * this program finds the maximum palindrome obtained by multiplying two
 * three-digit numbers
 *
 * Return: 1 (success)
 */

int main()
{
	int num1, num2, maxPalindrome = 0;

	for (num1 = 111; num1 <= 999; num1++)
	{
		for (num2 = num1; num2 <= 999; num2++)
		{
			if (isPalindrome(num1 * num2) == 1)
			{
				printf("%d x %d = %d\n", num1, num2, num1 * num2);
				if ((num1 * num2) > maxPalindrome)
					maxPalindrome = num1 * num2;
			}
		}
	}
	printf("\nThe maximum palindrome is: %d\n", maxPalindrome);

	return (1);
}



/**
 * isPalindrome - program that checks if a number is a palindrome
 *
 * @num: the number to be checked
 *
 * Return: 1 if the number is a palindrome, -1 otherwise
 */

int isPalindrome(int num)
{
	int i;

	for (i = 1; i <= (countDigits(num) / 2); i++)
	{
		if (((num / power(10, (countDigits(num) - i))) % 10) != ((num / power(10, i - 1)) % 10))
			return (-1);
	}

	return (1);
}



/**
 * countDigits - program that counts the number of digits in a given number
 *
 * @value: the number for which to count the digits
 *
 * Return: the count of digits in the number
 */

int countDigits(int value)
{
	int i;

	for (i = 0; value > 0; i++)
		value /= 10;

	return (i);
}



/**
 * power - program that calculates the power of a number
 *
 * @base: the base number
 * @exponent: the exponent
 *
 * Return: the result of base raised to the power of exponent
 */

int power(int base, int exponent)
{
	int i, result = base;

	if (exponent == 0)
		return (1);

	for (i = 1; i < exponent; i++)
		result = result * base;

	return (result);
}