#include "lists.h"

/**
 * *get_nodeint_at_index - program that returns the nth node of a linked list (listint_t)
 *
 * this function retrieves the node located at the given index in a singly linked list
 * of type 'listint_t';
 * the indexing starts from 0, where the head node has an index of 0,
 * the next node has an index of 1, and so on
 *
 * @head: a pointer to the head node of the linked list
 * @index: the index of the node to retrieve, starting at 0
 *
 * Return: a pointer to the node at the specified index,
 * or NULL if the index is out of bounds or the list is empty
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int currentIndex;

	for (currentIndex = 0; currentIndex < index && head != NULL; currentIndex++)
	{
		head = head->next;
	}

	return (head);
}