#include "../search_algos.h"

/**
 * free_list - program that frees a linked list of integers
 *
 * this function takes a pointer to the head of a linked list ('listint_t' type)
 * and frees (deallocates) all the nodes in the list;
 * it is a recursive function that traverses the list and frees each node;
 * it stops when it reaches a node that is NULL, indicating the end of the list
 *
 * @list: a pointer to the head of the list to be freed
 *
 * Return: nothing (void)
 */

void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}