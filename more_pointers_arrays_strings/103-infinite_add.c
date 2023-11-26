#include "main.h"

/**
 * infinite_add - program that adds two numbers represented as strings and stores the result
 *
 * this function takes two numbers in the form of strings and performs addition
 * on them as if they were integers;
 * the result of the addition is stored in the provided result buffer;
 * the function handles carrying digits and ensures that the result is stored correctly
 * without overflow
 *
 * we can assume that we will always get positive numbers, or 0;
 * we can assume that there will be only digits in the strings n1 and n2;
 * n1 and n2 will never be empty;
 * the buffer should have sufficient space to accommodate the result and a null
 * terminator;
 * if the result can not be stored in r, the function must return 0
 *
 * @num1_str: the first number provided as a string
 * @num2_str: the second number provided as a string
 * @result_str: a buffer to store the result of the addition
 * @result_size: the size of the result buffer
 *
 * Return: a pointer to the result buffer (result_str),
 * or NULL if the result buffer is not large enough to store the result
 */

char *infinite_add(char *num1_str, char *num2_str, char *result_str,
		   int result_size)
{
	int len_num1, len_num2;
	int tmp_len, result_len;
	int i;
	int digit_sum, digit_num1, digit_num2;
	int carry;
	char tmp_buffer[10000];

	result_len = i = len_num1 = len_num2 = digit_sum = digit_num1 =
	digit_num2 = carry = 0;

/* Calculate lengths of input number strings */
	while (num1_str[len_num1] != '\0')
		len_num1++;

	while (num2_str[len_num2] != '\0')
		len_num2++;

/* Check if result buffer is large enough */
	if (len_num1 + 2 > result_size || len_num2 + 2 > result_size)
		return (NULL);

	len_num1--;
	len_num2--;

/* Perform addition digit by digit */
	while (i <= len_num1 || i <= len_num2)
	{
		digit_num1 = digit_num2 = 0;

/* Extract individual digits from input strings */
		if (i <= len_num1)
			digit_num1 = num1_str[len_num1 - i] - '0';

		if (i <= len_num2 && (len_num2 - i) >= 0)
			digit_num2 = num2_str[len_num2 - i] - '0';

/* Perform addition of current digits and any carried value */
		digit_sum = digit_num1 + digit_num2 + carry;

/* Handle carrying if the sum is greater than or equal to 10 */
		if (digit_sum >= 10)
		{
			carry = 1;
			digit_sum -= 10;
		}

		else
			carry = 0;

/* Store the digit sum in the result buffer */
		result_str[i] = digit_sum + '0';
		i++;
		result_len++;
	}

/* Handle any remaining carry */
	if (carry > 0)
	{
		result_str[i] = carry + '0';
		result_str[i + 1] = '\0';
	}

	i = tmp_len = 0;

/* Reverse the result string */
	while (i <= result_len)
	{
		tmp_buffer[i] = result_str[result_len - i];
		tmp_len++;
		i++;
	}

	i = 0;

/* Copy the reversed result back to the result string */
	while (i < tmp_len)
	{
		if (result_str[i] == '\0')
		{
			break;
		}

		result_str[i] = tmp_buffer[i];
		i++;
	}

	return (result_str);
}