#include "main.h"

/**
 * main - the entry point
 *
 * program that calculates the minimum number of coins needed to make change
 * for an amount of money
 *
 * @argc: the number of command-line arguments
 * @argv: an array of strings containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char *argv[])
{
	int totalCents, numCoins = 0;

	if (argc == 2)
	{
		totalCents = atoi(argv[1]);

		while (totalCents > 0)
		{
			if (totalCents % 25 < totalCents)
			{
				totalCents -= 25;
				numCoins++;
			}
			else if (totalCents % 10 < totalCents)
			{
				totalCents -= 10;
				numCoins++;
			}
			else if (totalCents % 5 < totalCents)
			{
				totalCents -= 5;
				numCoins++;
			}
			else if (totalCents % 2 < totalCents)
			{
				totalCents -= 2;
				numCoins++;
			}
			else if (totalCents % 1 < totalCents)
			{
				totalCents -= 1;
				numCoins++;
			}
		}
	}

	else
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", numCoins);
	return (0);
}