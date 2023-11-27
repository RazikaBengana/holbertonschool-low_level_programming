#include "lists.h"

/**
 * *add_dnodeint_end - program that adds a new node at the end of a doubly linked list (dlistint_t)
 *
 * @head: a pointer to a pointer to the head node of the list
 * @n: the value to be stored in the new node
 *
 * Return: a pointer to the newly added node (the address of the new element), or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *last_node = *head;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}


	while (last_node->next != NULL)
		last_node = last_node->next;

	last_node->next = new_node;
	new_node->prev = last_node;

	return (new_node);
}