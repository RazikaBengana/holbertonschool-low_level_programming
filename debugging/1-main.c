#include "main.h"

/**
 * main - program that causes an infinite loop
 *
 * we have to comment out the part of the code that is causing the output to go into an infinite loop
 *
 * Return: 0 (success)
 */

int main(void)
{
	int i;

	printf("Infinite loop incoming :(\n");
	i = 0;

	/*
	 * while (i < 10)
	 * {
	 * putchar(i);
	 * }
	 */

	printf("Infinite loop avoided! \\o/\n");

	return (0);
}