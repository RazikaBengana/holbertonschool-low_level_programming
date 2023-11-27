#include "lists.h"

/**
 * *get_dnodeint_at_index - program that returns the nth node of a doubly linked list (dlistint_t)
 *
 * this function gets the node at a specific index in a doubly linked list
 *
 * @head: a pointer to the head of the doubly linked list
 * @index: the index of the node to retrieve, starting from 0
 *
 * Return: a pointer to the node at the specified index,
 * or NULL if if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int current_index = 0;

	if (head == NULL)
		return (NULL);

	for (current_node = head; current_node != NULL; current_node = current_node->next)
	{
		if (current_index == index)
			return (current_node);
		current_index++;
	}

	return (0);
}