#include "lists.h"

/**
 * *insert_dnodeint_at_index - program that inserts a new node at a given position in a doubly linked list
 *
 * if it is not possible to add the new node at index idx, do not add the new node and return NULL
 *
 * @h: a pointer to the head of the doubly linked list
 * @idx: the index at which the new node should be inserted, that starts at 0
 * @n: the data to be stored in the new node
 *
 * Return: a pointer to the newly inserted node (the address of the new node),
 * or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{

	dlistint_t *new_node, *current = *h;
	unsigned int current_index;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (current_index = 1; current_index < idx; current_index++)
	{
		current = current->next;
		if (current == NULL)
			return (NULL);
	}

	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current;
	new_node->next = current->next;
	current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}