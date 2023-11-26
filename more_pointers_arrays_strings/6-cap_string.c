#include "main.h"

/**
 * cap_string - program that capitalizes all words of a string
 *
 * separators of words: - space
                        - tabulation
			- new line
			- comma(,)
			- semicolon(;)
			- period(.)
			- exclamation point(!)
			- question mark(?)
			- double quotes(")
			- parentheses( () )
			- curly brackets ( {} )
 *
 * @s: the string to be capitalized
 *
 * Return: the pointer to the capitalized string
 */

char *cap_string(char *s)
{
	int index = 0;

	while (s[index])
	{
		while (!(s[index] >= 'a' && s[index] <= 'z'))
			index++;

		if (s[index - 1] == ' ' ||
		    s[index - 1] == '\t' ||
		    s[index - 1] == '\n' ||
		    s[index - 1] == ',' ||
		    s[index - 1] == ';' ||
		    s[index - 1] == '.' ||
		    s[index - 1] == '!' ||
		    s[index - 1] == '?' ||
		    s[index - 1] == '"' ||
		    s[index - 1] == '(' ||
		    s[index - 1] == ')' ||
		    s[index - 1] == '{' ||
		    s[index - 1] == '}' ||
		    index == 0)
			s[index] -= 32;
		index++;
	}

	return (s);
}