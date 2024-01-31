#include "../search_algos.h"


void free_skiplist(skiplist_t *list);


/**
 * init_express - program that initializes express lane pointers in a "skiplist"
 *
 * a skiplist is a data structure that facilitates faster search times within a list;
 * the "express lane" concept introduces shortcuts in the skiplist;
 * these express lanes link nodes in the list, allowing to skip multiple nodes in a single step;
 *
 * this function strategically places express lanes in the skiplist;
 * express lanes are set at intervals of approximately 'sqrt(size)' nodes;
 * this enables quicker traversal and search, especially in large lists
 *
 * @list: a pointer to the start of the skiplist
 * @size: the total number of elements in the skiplist
 *
 * Return: nothing (void)
 */

void init_express(skiplist_t *list, size_t size)
{
	const size_t step = sqrt(size);
	size_t i;
	skiplist_t *save;

	for (save = list, i = 0; i < size; ++i, list = list->next)
	{
		if (i % step == 0)
		{
			save->express = list;
			save = list;
		}
	}
}



/**
 * create_skiplist - program that creates a "skiplist" from a given array
 *
 * a "skiplist" is a special kind of list, similar to a regular list, but with extra shortcuts
 * for quicker access to its elements;
 * it's like having a main road (the list) with several fast lanes (extra layers) above it;
 * each fast lane skips several items of the main road, allowing us to move quickly to a specific
 * part of the list;
 *
 * this function allocates memory for each element in the array and adds it to the skiplist;
 * it also initializes the express lanes in the list for faster searching
 *
 * @array: a pointer to the array of integers to be added to the skiplist
 * @size: the number of elements in the array
 *
 * Return: a pointer to the head of the newly created skiplist, or NULL if memory allocation fails
 */

skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *node;
	size_t save_size;

	list = NULL;
	save_size = size;

	while (array && size--)
	{
		node = malloc(sizeof(*node));

		if (!node)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->express = NULL;
		node->next = list;
		list = node;
	}
	init_express(list, save_size);

	return (list);
}