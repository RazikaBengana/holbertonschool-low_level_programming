#include "main.h"

/**
 * main - program that tests function that prints if integer is positive or negative
 *
 * this program must test that the function positive_or_negative gives the correct output when given a case of 0
 * (it represents another main function based on one provided initially, that just tests the case 0)
 *
 * Return: 0 (success)
 */

int main(void)
{
	int i;

	i = 0;
	positive_or_negative(i);

	return (0);
}