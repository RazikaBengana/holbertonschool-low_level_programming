#include "search_algos.h"

/**
 * linear_skip - program that performs a "linear search" on a skip list to find a specified value
 *
 * this function searches for a given value in a skip list using a linear search algorithm;
 * it traverses through the skip list using the express lanes (if available) to efficiently
 * locate the approximate position of the value;
 * once the range is determined, it performs a standard linear search in that range to find
 * the exact position of the value;
 *
 * we can assume that list will be sorted in ascending order;
 * every time we compare a value in the list to the value we are searching, we have to print this value
 *
 * @list: a pointer to the first element of the skip list
 * @value: the value to be searched within the skip list
 *
 * Return: a pointer to the node in the skip list containing the value, or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *probe_node = list;

	if (!list)
		return (NULL);

	while (probe_node->n < value)
	{
		if (!probe_node->express)
			break;

		list = probe_node;
		probe_node = probe_node->express;
		printf("Value checked at index [%zu] = [%d]\n", probe_node->index, probe_node->n);
	}

	if (probe_node->n >= value)
	{
		printf("Value found between indexes [%zu] and [%zu]\n", list->index, probe_node->index);
		list = list;
	}

	else
	{
		for (list = probe_node; list->next; list = list->next)
			;
		printf("Value found between indexes [%zu] and [%zu]\n", probe_node->index, list->index);
	}

	while (probe_node)
	{
		printf("Value checked at index [%zu] = [%d]\n", probe_node->index, probe_node->n);

		if (probe_node->n == value)
			return (probe_node);

		probe_node = probe_node->next;
	}
	return (NULL);
}