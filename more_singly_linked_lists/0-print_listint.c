#include "lists.h"

/**
 * print_listint - program that prints all the elements of a linked list of integers (listint_t)
 *
 * @h: a pointer to the head of the linked list
 *
 * Return: the number of nodes in the linked list
 */

size_t print_listint(const listint_t *h)
{
	int element_count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		element_count++;
	}

	return (element_count);
}