#include "main.h"

/**
 * leet - program that encodes a string into 1337
 *
 * letters a and A should be replaced by 4
 * letters e and E should be replaced by 3
 * letters o and O should be replaced by 0
 * letters t and T should be replaced by 7
 * letters l and L should be replaced by 1
 *
 * @s: the string to be encoded
 *
 * Return: the pointer to the encoded string
 */

char *leet(char *s)
{
	int index = 0;
	int leet_index;
	char leet_chars[10] = {'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'};
	char leet_codes[10] = {'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'};

	while (s[index])
	{
		for (leet_index = 0; leet_index < 10; leet_index++)
			if (s[index] == leet_chars[leet_index])
				s[index] = leet_codes[leet_index];
		index++;
	}

	return (s);
}