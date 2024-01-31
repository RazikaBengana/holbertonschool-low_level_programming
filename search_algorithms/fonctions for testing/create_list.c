#include "../search_algos.h"


void free_list(listint_t *list);


/**
 * create_list - program that creates a singly linked list from an array
 *
 * this function takes an array of integers and its size as inputs;
 * it then creates a singly linked list where each node contains one element from the array;
 * the list is created in reverse order, with the last element of the array becoming the head of the list;
 * in case of memory allocation failure, it frees the already allocated memory and returns NULL
 *
 * @array: a pointer to the array of integers to be converted
 * @size: the number of elements in the array
 *
 * Return: a pointer to the head of the newly created list, or NULL if memory allocation fails
 */

listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;

	list = NULL;

	while (array && size--)
	{
		node = malloc(sizeof(*node));

		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->next = list;
		list = node;
	}

	return (list);
}