#include "lists.h"

/**
 * pop_listint - program that deletes the head node of a linked list (listint_t),
 * and returns the data of the head node (n)
 *
 * this function removes the first element from the linked list pointed to by `head`
 *
 * @head: a pointer to the pointer of the head node
 *
 * Return: the value of the removed first element, or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *first_node;
	int popped_value;

	if (*head == NULL)
		return (0);

	if (*head != NULL)
	{
		first_node = *head;
		popped_value = (*head)->n;
		*head = (*head)->next;

		free(first_node);
	}

	return (popped_value);
}