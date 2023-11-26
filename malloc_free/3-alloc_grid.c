#include "main.h"

/**
 * alloc_grid - program that returns a pointer to a 2 dimensional array of integers
 *
 * each element of the grid should be initialized to 0
 * if width or height is 0 or negative, we have to return NULL
 *
 * @height: the height of the grid
 * @width: the width of the grid
 *
 * Return: a pointer to the 2-dimensional array, or NULL if it fails
 */

int **alloc_grid(int width, int height)
{
	int row, col;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (row = 0; row < height; row++)
	{
		grid[row] = malloc(width * sizeof(int));

		if (grid[row] == NULL)
		{
			for (col = 0; col < row; col++)
				free(grid[col]);
			free(grid);
			return (NULL);
		}

		for (col = 0; col < width; col++)
		{
			grid[row][col] = 0;
		}
	}

	return (grid);
}