#include "main.h"

/**
 * free_grid - program that frees a 2 dimensional grid previously created by the alloc_grid function
 *
 * the free_grid function deallocates the memory used by the 2-dimensional grid,
 * which was previously created by the alloc_grid function
 *
 * @height: the height of the grid
 * @grid: the grid to be freed
 *
 * Return: nothing (void)
 */

void free_grid(int **grid, int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(grid[height]);
		free(grid);
	}
}