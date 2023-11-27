#include "lists.h"

/**
 * *add_dnodeint - program that adds a new node at the beginning of a a doubly linked list (dlistint_t)
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @n: the value to be stored in the new node
 *
 * Return: a pointer to the newly created node (the address of the new element), or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	while (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}