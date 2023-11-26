#include "lists.h"

/**
 * delete_nodeint_at_index - program that deletes the node at index 'index'
 * of a linked list (listint_t)
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @index: the index of the node that should be deleted ---> it starts at 0
 *
 * Return: 1 if it succeeded, or -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int position;
	listint_t *current_node, *previous_node = *head;

	if (previous_node == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(previous_node);

		return (1);
	}

	for (position = 0; position < (index - 1); position++)
	{
		if (previous_node->next == NULL)
			return (-1);
		previous_node = previous_node->next;
	}

	current_node = previous_node->next;
	previous_node->next = current_node->next;
	free(current_node);

	return (1);
}