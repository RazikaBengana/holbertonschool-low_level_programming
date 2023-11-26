#include "lists.h"

/**
 * *add_nodeint_end - program that adds a new integer node at the end of a linked list (listint_t)
 *
 * this code adds a new integer node with the given value n at the end of the linked list,
 * and it returns the address of the head of the linked list, which could either
 * be the same as before (if the list was not empty) or the new element (if the list was empty)
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @n: the value to be added in the new node
 *
 * Return: a pointer to the head of the updated linked list after adding
 * the new node at the end, (the address of the new head),
 * or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{

	listint_t *new_node, *current_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;

	else
	{
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}

	return (*head);
}