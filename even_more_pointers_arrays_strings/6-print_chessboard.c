#include "main.h"

/**
 * print_chessboard - program that prints the chessboard
 *
 * this function prints the chessboard using the provided 2D array 'a';
 * each element of the array represents a square on the chessboard,
 * and the function prints the characters in the array to represent the chessboard
 *
 * @a: the 2D array representing the chessboard
 *
 * Return: nothing (void)
 */

void print_chessboard(char (*a)[8])
{
	int row, column;

	for (row = 0; row < 8; row++)
	{
		for (column = 0; column < 8; column++)
			_putchar(a[row][column]);

		_putchar('\n');
	}
}