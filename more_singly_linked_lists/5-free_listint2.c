#include "lists.h"

/**
 * free_listint2 - program that frees a linked list of integers (listint_t)
 *
 * this function frees a linked list of integers and sets the head pointer to NULL
 *
 * @head: a pointer to a pointer to the head node of the linked list
 *
 * Return: nothing (void)
 */

void free_listint2(listint_t **head)
{
	listint_t *current_node;

	if (head == NULL)
		return;

	while (*head)
	{
		current_node = (*head)->next;
		free(*head);
		*head = current_node;
	}

	*head = NULL;
}