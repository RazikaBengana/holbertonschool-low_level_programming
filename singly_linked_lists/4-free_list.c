#include "lists.h"

/**
 * free_list - program that frees memory occupied by a linked list
 *
 * this function frees the memory occupied by each node in the linked list;
 * it iterates through the list, freeing both the string and the node itself;
 * after calling this function, the linked list will be fully deallocated
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: nothing (void)
 */

void free_list(list_t *head)
{
	list_t *current_node;

	while ((current_node = head) != NULL)
	{
		head = head->next;
		free(current_node->str);
		free(current_node);
	}
}