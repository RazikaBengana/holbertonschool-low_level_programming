#include "lists.h"

/**
 * sum_listint - program that returns the sum of all the data (n) of a linked list (listint_t)
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: the sum of integer elements in the linked list, or 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	int total_sum = 0;

	if (head == NULL)
		return (0);

	while (head)
	{
		total_sum += head->n;
		head = head->next;
	}

	return (total_sum);
}