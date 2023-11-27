#include "lists.h"

/**
 * print_dlistint - program that prints all the elements of a doubly linked list (dlistint_t)
 *
 * @h: a pointer to the head of the doubly linked list
 *
 * Return: the number of nodes in the list
 */

size_t print_dlistint(const dlistint_t *h)
{
	int node_count = 0;

	while (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_count++;
	}

	return (node_count);
}