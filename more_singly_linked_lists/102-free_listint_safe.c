#include "lists.h"

/**
 * free_listint_safe - program that frees a linked list of integers safely,
 * handling cyclic lists
 *
 * a cyclic list refers to a linked list that contains a loop,
 * meaning that there is a sequence of nodes in the list that eventually
 * leads back to a previously visited node, creating a cycle within the linked list;
 * the code is designed to safely free a linked list of integers, even if it
 * contains a cycle
 *
 * this function can free lists with a loop;
 * we should go through the list only once;
 * the function sets the head to NULL
 *
 * @head: a pointer to the head of the linked list
 *
 * Return: the number of nodes freed
 */

size_t free_listint_safe(listint_t **head)
{
	listint_t *node_to_free;
	listint_t *current_node;
	list_address_t *address_list_head;
	list_address_t *address_checker;
	size_t nodes_freed_count;

	nodes_freed_count = 0;
	current_node = *head;
	address_list_head = NULL;

	if (head != NULL)
	{
		while (current_node != NULL)
		{
			address_checker = address_list_head;

			while (address_checker != NULL)
			{
				if (current_node == address_checker->node_address)
				{
					free(current_node);
					free_list_nodes(address_list_head);
					*head = NULL;
					return (nodes_freed_count);
				}

				address_checker = address_checker->next;
			}

			node_to_free = current_node;

			if (add_node_to_list(&address_list_head, current_node) == NULL)
			{
				free_list_nodes(address_list_head);
				exit(98);
			}

			current_node = current_node->next;
			free(node_to_free);
			nodes_freed_count++;
		}

		free_list_nodes(address_list_head);
		*head = NULL;
	}

	return (nodes_freed_count);
}