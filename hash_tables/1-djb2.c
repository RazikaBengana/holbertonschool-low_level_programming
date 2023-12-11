#include "hash_tables.h"

/**
 * hash_djb2 - program that generates a hash value for a given string using the "djb2" algorithm
 *
 * this function processes each character of the input string, combining the previous hash value and
 * the current character to produce a new hash value;
 * this process repeats until the end of the string;
 *
 * the hash value starts at 5381, a prime number;
 * in each step, the hash value is left-shifted by 5 places and then added to itself
 * (effectively multiplying it by 33) before adding the current character value;
 *
 * @str: the string to be hashed
 *
 * Return: the hash value of the string
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hashValue;
	int currentChar;

	hashValue = 5381;

	while ((currentChar = *str++))
	{
		hashValue = ((hashValue << 5) + hashValue) + currentChar; /* hashValue * 33 + currentChar */
	}
	return (hashValue);
}
