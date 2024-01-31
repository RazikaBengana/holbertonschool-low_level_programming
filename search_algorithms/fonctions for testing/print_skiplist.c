#include "../search_algos.h"

/**
 * print_skiplist - program that prints the elements of a skip list with their indexes
 *
 * this function prints a skip list's contents, which is structured for fast search;
 *
 * it performs two traversals:
 * 1. Regular lane: iterates over the standard linked list, printing each node's index and value
 * 2. Express lane: goes through the skip list's shortcuts, printing each node's index and value
 *
 * @list: a pointer to the head of the skip list
 *
 * Return: nothing (void)
 */

void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *current_node;

	printf("List :\n");
	for (current_node = list; current_node; current_node = current_node->next)
	{
		printf("Index[%lu] = [%d]\n", current_node->index, current_node->n);
	}
	printf("\nExpress lane :\n");
	for (current_node = list; current_node; current_node = current_node->express)
	{
		printf("Index[%lu] = [%d]\n", current_node->index, current_node->n);
	}
	printf("\n");
}