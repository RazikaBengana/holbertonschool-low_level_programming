#include "lists.h"

/**
 * print_list - program that prints all the elements of a linked list (list_t)
 *
 * this function traverses a linked list and prints each node's content along with its length;
 * if str is NULL, we have to print [0] (nil)
 *
 * @h: a pointer to the head of the linked list
 *
 * Return: the number of nodes in the linked list
 */

size_t print_list(const list_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{

		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next;
		node_count++;
	}

	return (node_count);
}