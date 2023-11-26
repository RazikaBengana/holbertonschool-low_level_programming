#include "lists.h"

/**
 * find_listint_loop - program that finds a loop in a linked list of integers
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: a pointer to the node where the loop begins,
 * or NULL if no loop is found
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current_node;

	while (list_head != NULL)
	{
		current_node = list_head;
		list_head = list_head->next;

		if (current_node < list_head)
			return (list_head);
	}

	return (NULL);
}