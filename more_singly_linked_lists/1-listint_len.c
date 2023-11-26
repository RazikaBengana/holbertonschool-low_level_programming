#include "lists.h"

/**
 * listint_len - program that returns the number of elements in a linked list of integers (listint_t)
 *
 * @h: a pointer to the head node of the linked list
 *
 * Return: the number of nodes in the linked list
 */

size_t listint_len(const listint_t *h)
{
	int node_count = 0;

	while (h != NULL)
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}