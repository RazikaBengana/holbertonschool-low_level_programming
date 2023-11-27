#include "lists.h"

/**
 * sum_dlistint - program that returns the sum of all the data (n) of a doubly linked list (dlistint_t)
 *
 * this function calculates the sum of all elements in a doubly linked list
 *
 * @head: a pointer to the head node of the doubly linked list
 *
 * Return: the sum of all elements in the doubly linked list, or 0 if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int totalSum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		totalSum += head->n;
		head = head->next;
	}

	return (totalSum);
}