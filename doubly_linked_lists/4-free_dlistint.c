#include "lists.h"

/**
 * free_dlistint - program that frees a doubly linked list (dlistint_t)
 *
 * @head: a pointer to the head of the doubly linked list
 *
 * Return: nothing (void)
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;

		free(current_node);
	}
}