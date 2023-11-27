#include "lists.h"

/**
 * delete_dnodeint_at_index - program that deletes the node at a given index
 * in a doubly linked list (dlistint_t)
 *
 * @head: a pointer to the head of the doubly linked list
 * @index: the index of the node that should be deleted, that starts at 0
 *
 * Return: 1 if it succeeded, or -1 if it failed (if the index is out of bounds)
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	dlistint_t *previous_node;
	unsigned int current_index;

	current_node = *head;

/* Move to the beginning of the list */
	if (current_node != NULL)
	{
		while (current_node->prev != NULL)
		{
			current_node = current_node->prev;
		}
	}

	current_index = 0;

	while (current_node != NULL)
	{
		if (current_index == index)
		{
			if (current_index == 0)
			{
				*head = current_node->next;

				if (*head != NULL)
					(*head)->prev = NULL;
			}

			else
			{
				previous_node->next = current_node->next;

				if (current_node->next != NULL)
					current_node->next->prev = previous_node;
			}

			free(current_node);
			return (1); /* Node deleted successfully */
		}

		previous_node = current_node;
		current_node = current_node->next;
		current_index++;
	}

	return (-1); /* Index out of bounds */
}