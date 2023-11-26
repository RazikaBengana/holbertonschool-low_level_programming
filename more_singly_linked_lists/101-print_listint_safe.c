#include "lists.h"

/**
 * add_node_to_list - program that adds a node to the beginning of a linked list
 *
 * @list_head: a pointer to the head of the list
 * @node_address: the address of the node to be added
 *
 * Return: a pointer to the newly added node
 */

listadd_t *add_node_to_list(listadd_t **list_head, const listint_t *node_address)
{
	listadd_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		free_list_nodes(*list_head);
		exit(98);
	}

	new_node->address = (void *)node_address;
	new_node->next = *list_head;
	*list_head = new_node;

	return (new_node);
}


/**
 * free_list_nodes - program that frees all nodes in a linked list
 *
 * @list_head: a pointer to the head of the list
 *
 * Return: nothing (void)
 */

void free_list_nodes(listadd_t *list_head)
{
	listadd_t *node_to_free;

	while (list_head != NULL)
	{
		node_to_free = list_head;
		list_head = list_head->next;
		free(node_to_free);
	}
}


/**
 * print_listint_safe - program that safely prints a linked list to avoid loops
 *
 * this function can print lists with a loop;
 * we should go through the list only once;
 * if the function fails, we exit the program with status 98
 *
 * @list_head: a pointer to the head of the list to be printed
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *list_head)
{
	listadd_t *visited_nodes;
	listadd_t *checker;
	unsigned int node_count;

	node_count = 0;
	visited_nodes = NULL;
	while (list_head != NULL)
	{
		checker = visited_nodes;

		while (checker != NULL)
		{
			if (list_head == checker->address)
			{
				printf("-> [%p] %d\n", (void *)list_head,
				       list_head->n);
				free_list_nodes(visited_nodes);
				return (node_count);
			}
			checker = checker->next;
		}
		printf("[%p] %d\n", (void *)list_head, list_head->n);
		add_node_to_list(&visited_nodes, list_head);
		list_head = list_head->next;
		node_count++;
	}
	free_list_nodes(visited_nodes);

	return (node_count);
}