#include "../search_algos.h"

/**
 * free_skiplist - program that frees a skiplist
 *
 * this function traverses through a skiplist and frees each node;
 * it starts from the head of the list and recursively calls itself after freeing the current node,
 * thus freeing the entire list;
 * this function is typically used when the skiplist is no longer needed, to prevent memory leaks
 *
 * @list: a pointer to the skiplist to be freed
 *
 * Return: nothing (void)
 */

void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_skiplist(node);
	}
}