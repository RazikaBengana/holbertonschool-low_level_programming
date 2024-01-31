#include "search_algos.h"

/**
 * jump_list - program that performs a "jump search" on a singly linked list
 *
 * this function searches for a specific value in a singly linked list using the jump search algorithm;
 * it jumps ahead by a fixed number of nodes (based on the square root of the size of the list)
 * and checks if the value is present;
 * if the value is greater than the current node, it moves to the next block of nodes;
 * once it finds an interval where the value could be, it performs a linear search in that interval;
 *
 * we can assume that list will be sorted in ascending order;
 * every time we compare a value in the list to the value we are searching, we have to print this value
 *
 * @list: a pointer to the first node of the singly linked list
 * @size: the total number of nodes in the list
 * @value: the value to search for in the list
 *
 * Return: a pointer to the first node where value is located, or NULL if value is not present in the list
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t currentIndex = 0, jumpStep = sqrt(size), previousIndex = 0, lastJumpIndex = 0;
	listint_t *previousNode = list;

	if (!list)
		return (NULL);

	while (list->n < value)
	{
		for (lastJumpIndex = currentIndex, previousNode = list, previousIndex = 0; list->next && previousIndex < jumpStep; previousIndex++)
		{
			list = list->next;
			currentIndex++;
		}
		printf("Value checked at index [%zu] = [%d]\n", currentIndex, list->n);

		if (!list->next)
			break;
	}

	if (!list->next)
		jumpStep = lastJumpIndex;

	else
		jumpStep = currentIndex >= jumpStep ? currentIndex - jumpStep : 0;

	printf("Value found between indexes [%zu] and [%zu]\n", jumpStep, currentIndex);

	currentIndex = currentIndex >= size ? size - 1 : currentIndex;
	list = previousNode;

	while (list)
	{
		printf("Value checked at index [%zu] = [%d]\n", jumpStep, list->n);

		if (list->n == value)
			return (list);

		jumpStep++;
		list = list->next;
	}
	return (NULL);
}