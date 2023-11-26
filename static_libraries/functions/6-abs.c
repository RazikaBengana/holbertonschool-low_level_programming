#include "../main.h"

/**
 * _abs - program that computes the absolute value of an integer
 *
 * @n: the number to be measured
 *
 * Return: the absolute value of the integer
 */

int _abs(int n)
{
	if (n >= 0)
	{
		return (n);
	}

	else
	{
		return (-n);
	}
}