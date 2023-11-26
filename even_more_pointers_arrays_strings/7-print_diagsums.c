#include "main.h"

/**
 * print_diagsums - program that prints the sum of the two diagonals of a square matrix of integers
 *
 * @a: the array representing the square matrix
 * @size: the size of the matrix
 *
 * Return: nothing (void)
 */

void print_diagsums(int *a, int size)
{
	int row, column;
	int mainDiagonalSum = 0, antiDiagonalSum = 0;

	for (row = 0; row < size; row++)
		mainDiagonalSum += a[row * size + row];

	for (column = size - 1; column >= 0; column--)
		antiDiagonalSum += a[(size - 1 - column) * size + column];

	printf("%d, %d\n", mainDiagonalSum, antiDiagonalSum);
}