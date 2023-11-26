#include "lists.h"

/**
 * reverse_listint - program that reverses a linked list of integers (listint_t)
 *
 * this function reverses the order of the nodes in a singly linked list of integers;
 * it takes a pointer to the head of the list as input and returns a pointer
 * to the new head of the reversed list
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: a pointer to the first node (new head) of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *previous;

	if (head == NULL || *head == NULL)
		return (NULL);

	previous = NULL;

	while ((*head)->next != NULL)
	{
		current = (*head)->next;
		(*head)->next = previous;
		previous = *head;
		*head = current;
	}

	(*head)->next = previous;

	return (*head);
}