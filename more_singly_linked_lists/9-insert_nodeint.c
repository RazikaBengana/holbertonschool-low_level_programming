#include "lists.h"

/**
 * *insert_nodeint_at_index - program that inserts a new node at a given position
 *
 * this function inserts a new node with a given value at a specific index
 * in a linked list;
 * if it is not possible to add the new node at index idx, we do not add the new node
 * and we return NULL
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @idx: the index of the list where the new node should be added ---> it starts at 0
 * @n: the value to be stored in the new node
 *
 * Return: the address of the new node (a pointer to the newly inserted node),
 * or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int position;
	listint_t *new_node, *current_node = *head;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = current_node;
		*head = new_node;
		return (new_node);
	}

	for (position = 0; position < (idx - 1); position++)
	{
		if (current_node == NULL || current_node->next == NULL)
			return (NULL);

		current_node = current_node->next;
	}

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}