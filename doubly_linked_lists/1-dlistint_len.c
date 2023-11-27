#include "lists.h"

/**
 * dlistint_len - program that returns the number of elements (the length)
 * in a doubly linked list (dlistint_t)
 *
 * @h: a pointer to the head of the doubly linked list
 *
 * Return: the number of nodes in the doubly linked list
 */

size_t dlistint_len(const dlistint_t *h)
{
	int node_count = 0;

	while (h)
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}