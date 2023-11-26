#include "lists.h"

/**
 * *add_nodeint - program that adds a new node at the beginning of a linked list (listint_t)
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @n: the value to be added to the new node
 *
 * Return: a pointer to the newly added node at the beginning (the address of the new head),
 * or NULL if it failed
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}