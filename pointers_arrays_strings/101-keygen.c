#include "main.h"

#define TARGET_SUM 2772

/**
 * main - the entry point
 *
 * program that generates random valid passwords for the program "101-crackme"
 * (whose character values sum up to a target value)
 *
 * this function generates a random password by selecting characters
 * whose ASCII values are within the range [48, 126], such that the sum
 * of these values equals the specified target sum (TARGET_SUM)
 *
 * Return: 0 (success)
 */

int main(void)
{
	int currentSum = 0;      /* Tracks the current sum of character values in the password */
	int charValue = 0;       /* Stores the ASCII value of the currently selected character */
	int index = 0;           /* Index to keep track of the current position in the password */
	char password[100];      /* Array to store the generated password */

	srand(time(NULL));       /* Seed the random number generator */

/* Generate the password while ensuring the sum of character values meets the target */
	while (currentSum < TARGET_SUM)
	{

/* If remaining sum is too small, backtrack by subtracting last character value */
		if (TARGET_SUM - currentSum < 48)
			currentSum -= password[--index];

/* If remaining sum is within the range of a single character, set charValue accordingly */
		else if (TARGET_SUM - currentSum <= 126)
			charValue = TARGET_SUM - currentSum;

/* If remaining sum is larger, select a random character value in the specified range */
		else
			charValue = rand() % (126 - 48) + 48;

/* If charValue is non-zero, add it to the password and update currentSum */
		if (charValue)
		{
			password[index++] = charValue;
			currentSum += charValue;
		}

		charValue = 0;   /* Reset charValue for the next iteration */
	}

	password[index] = '\0';  /* Add null terminator to mark the end of the password */
	printf("%s", password);  /* Print the generated password */

	return (0);
}