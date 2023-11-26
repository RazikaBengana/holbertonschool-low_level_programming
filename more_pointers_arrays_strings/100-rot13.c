#include "main.h"

/**
 * rot13 - program that encodes a string using rot13
 *
 * this function iterates through the characters in the input string and performs
 * rot13 encoding on alphabetical characters (both uppercase and lowercase);
 *
 * the rot13 encoding shifts each character by 13 positions in the alphabet;
 * non-alphabetical characters remain unchanged
 *
 * @input: the input string to be encoded using rot13
 *
 * Return: a pointer to the encoded string, which is the same as the input string
 */

char *rot13(char *input)
{
	char *encodedResult;
	char baseCharacter;
	char encodedCharacter;

	int currentIndex;

	encodedResult = input;

	for (currentIndex = 0; input[currentIndex] != '\0'; currentIndex++)
	{
		baseCharacter = ('a' <= input[currentIndex] &&
				 input[currentIndex] <= 'z') ? 'a' : 'A';

		encodedCharacter = (input[currentIndex] - baseCharacter +
				    13) % 26 + baseCharacter;

		if (('a' <= input[currentIndex] && input[currentIndex] <= 'z')
		    || ('A' <= input[currentIndex] && input[currentIndex] <= 'Z'))
		{
			input[currentIndex] = encodedCharacter;
		}
	}

	return (encodedResult);
}