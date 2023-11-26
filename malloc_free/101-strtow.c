#include "main.h"

/**
 * word_length - program that calculates the length of a word within a string
 *
 * @str: the input string
 *
 * Return: the length of the word
 */

int word_length(char *str)
{
	int index = 0, length = 0;

	while (*(str + index) && *(str + index) != ' ')
	{
		length++;
		index++;
	}

	return (length);
}


/**
 * count_words - program that counts the number of words in a string
 *
 * words are separated by one or more spaces
 *
 * @str: the input string
 *
 * Return: the count of words
 */

int count_words(char *str)
{
	int index = 0, word_count = 0, str_length = 0;

	for (index = 0; *(str + index); index++)
		str_length++;

	for (index = 0; index < str_length; index++)
	{
		if (*(str + index) != ' ')
		{
			word_count++;
			index += word_length(str + index);
		}
	}

	return (word_count);
}


/**
 * strtow - program that splits a string into an array of words
 *
 * this function takes a null-terminated string as input and divides it into
 * an array of individual words;
 * it dynamically allocates memory for the word array and each word;
 * the words are separated by one or more spaces;
 * the function uses the count of words to determine the required memory
 * and iterates through the string to extract each word
 *
 * each element of this array should contain a single word, null-terminated;
 * the last element of the returned array should be NULL;
 * words are separated by spaces;
 * we return NULL if str == NULL or str == ""
 *
 * @str: the input string
 *
 * Return: a pointer to an array of strings (words), or NULL if it fails
 */

char **strtow(char *str)
{
	char **word_array;
	int index = 0, word_count, word_index, letters, letter_index;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	word_array = malloc(sizeof(char *) * (word_count + 1));
	if (word_array == NULL)
		return (NULL);

	for (word_index = 0; word_index < word_count; word_index++)
	{
		while (str[index] == ' ')
			index++;

		letters = word_length(str + index);

		word_array[word_index] = malloc(sizeof(char) * (letters + 1));

		if (word_array[word_index] == NULL)
		{
			for (; word_index >= 0; word_index--)
				free(word_array[word_index]);

			free(word_array);
			return (NULL);
		}

		for (letter_index = 0; letter_index < letters; letter_index++)
			word_array[word_index][letter_index] = str[index++];

		word_array[word_index][letter_index] = '\0';
	}
	word_array[word_index] = NULL;

	return (word_array);
}