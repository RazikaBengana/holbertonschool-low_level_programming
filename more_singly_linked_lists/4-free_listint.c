#include "lists.h"

/**
 * free_listint - program that frees all nodes in a linked list of integers (listint_t)
 *
 * @head: a pointer to the head node of the linked list
 *
 * Return: nothing (void)
 */

void free_listint(listint_t *head)
{
	listint_t *current_node;

	while (head != NULL)
	{
		current_node = head->next;
		free(head);
		head = current_node;
	}
}