#include "main.h"

/**
 * rev_string - program that reverses a string
 *
 * @str: the string to reverse
 *
 * Return: nothing (void)
 */

void rev_string(char *str)
{
	int start = 0;
	int end;
	char temp;
	int i;

	while (str[start] != '\0')
		start++;

	end = start - 1;

	for (i = 0; i < start / 2; i++)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		end--;
	}
}