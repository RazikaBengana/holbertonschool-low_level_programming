#include "lists.h"


int calculateValue1(int length);
int calculateValue2(char *str, int length);
int calculateValue3(char *str, int length);
int calculateValue4(char *str, int length);
int calculateValue5(char *str, int length);
int calculateValue6(char character);



/**
 * main - the entry point of the program
 *
 * we have to write a keygen for the program "crackme5"
 *
 * Usage of the crackme: ./crackme5 username key;
 * Usage for the keygen: ./keygen5 username;
 *
 * the crackme will segfault if we do not enter the correct key for the user;
 * our keygen should print a valid key for the username
 *
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0 (success)
 */

int main(int argc, char **argv)
{
	long data[] = {
		0x3877445248432d41,
		0x42394530534e6c37,
		0x4d6e706762695432,
		0x74767a5835737956,
		0x2b554c59634a474f,
		0x71786636576a6d34,
		0x723161513346655a,
		0x6b756f494b646850
	};
	char password[7];
	char *inputName = argv[1];
	int inputLength = strlen(inputName);
	int returnValue = argc;

	returnValue = calculateValue1(inputLength);
	password[0] = ((char *)data)[returnValue];

	returnValue = calculateValue2(inputName, inputLength);
	password[1] = ((char *)data)[returnValue];

	returnValue = calculateValue3(inputName, inputLength);
	password[2] = ((char *)data)[returnValue];

	returnValue = calculateValue4(inputName, inputLength);
	password[3] = ((char *)data)[returnValue];

	returnValue = calculateValue5(inputName, inputLength);
	password[4] = ((char *)data)[returnValue];

	returnValue = calculateValue6(inputName[0]);
	password[5] = ((char *)data)[returnValue];

	password[6] = 0;
	printf("%s", password);
	return (0);
}



/**
 * calculateValue1 - program that calculates a value based on the input length
 *
 * @length: the length of the input string
 *
 * Return: the calculated value
 */

int calculateValue1(int length)
{
	return ((length ^ 0x3b) & 0x3f);
}



/**
 * calculateValue2 - program that calculates a value based on characters in a string
 *
 * @str: the input string
 * @length: the length of the input string
 *
 * Return: the calculated value
 */

int calculateValue2(char *str, int length)
{
	int result = 0;
	int i = 0;

	for (; i < length; i++)
		result += str[i];

	return ((result ^ 0x4f) & 0x3f);
}



/**
 * calculateValue3 - program that calculates a value based on characters in a string
 *
 * @str: the input string
 * @length: the length of the input string
 *
 * Return: the calculated value
 */

int calculateValue3(char *str, int length)
{
	int result = 1;
	int i = 0;

	for (; i < length; i++)
		result *= str[i];

	return ((result ^ 0x55) & 0x3f);
}



/**
 * calculateValue4 - program that calculates a value based on characters in a string
 *
 * @str: the input string
 * @length: the length of the input string
 *
 * Return: the calculated value
 */

int calculateValue4(char *str, int length)
{
	int result = str[0];
	int i = 0;

	for (; i < length; i++)
	{
		if (str[i] > result)
			result = str[i];
	}

	srand(result ^ 0xe);
	return (rand() & 0x3f);
}



/**
 * calculateValue5 - program that calculates a value based on characters in a string
 *
 * @str: the input string
 * @length: the length of the input string
 *
 * Return: the calculated value
 */

int calculateValue5(char *str, int length)
{
	int result = 0;
	int i = 0;

	for (; i < length; i++)
		result += str[i] * str[i];

	return ((result ^ 0xef) & 0x3f);
}



/**
 * calculateValue6 - program that calculates a value based on a character
 *
 * @character:the input character
 *
 * Return: the calculated value
 */

int calculateValue6(char character)
{
	int result = 0;
	int i = 0;

	for (; character > i; i++)
		result = rand();

	return ((result ^ 0xe5) & 0x3f);
}