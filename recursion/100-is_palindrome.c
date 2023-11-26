#include "main.h"

/**
 * _recursive_strlen - program that finds the length of a string using recursion
 *
 * @str: the string to find the length of
 *
 * Return: the length of the string
 */

int _recursive_strlen(char *str)
{
	int length = 0;

	if (*str != '\0')
	{
		length++;
		return (length + _recursive_strlen(str + 1));
	}
	return (length);
}


/**
 * _recursive_palindrome_check - program that checks if a substring is a palindrome
 * using recursion
 *
 * this function compares characters at the beginning and end of a given substring
 * to determine if it's a palindrome;
 * it employs a recursive approach to gradually narrow down the substring until
 * the base case is reached
 *
 * @str: the substring to check for palindrome
 *
 * @length: the length of the current substring
 *
 * Return: 1 if the substring is a palindrome, otherwise 0
 */

int _recursive_palindrome_check(char *str, int length)
{
	if (length <= 1)
		return (1);

/* If the first and last characters of the substring do not match, it's not a palindrome */
	if (*str != str[length - 1])
		return (0);
	else
/* Recurse on the remaining substring without the first and last characters */
		return (_recursive_palindrome_check((str + 1), (length - 2)));
}


/**
 * is_palindrome - program that checks if a given string is a palindrome
 *
 * this function serves as the entry point for checking whether a given string
 * is a palindrome or not;
 * it calculates the length of the string and then calls the recursive palindrome
 * checking function
 *
 * @str: the string to check for palindrome
 *
 * Return: 1 if it is a palindrome, otherwise 0
 */

int is_palindrome(char *str)
{
/* Calculate the length of the string */
	int string_length = _recursive_strlen(str);

/* Base case: A string of length 0 or 1 is always a palindrome */
	if (string_length <= 1)
		return (1);

/* Call the recursive palindrome checking function with the string and its length */
	return (_recursive_palindrome_check(str, string_length));
}