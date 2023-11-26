#include "lists.h"

/**
 * add_node_end - program that adds a new node at the end of a linked list (list_t)
 *
 * str needs to be duplicated
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @str: the string to be stored in the new node
 *
 * Return: the address of the new element
 * (the updated head of the linked list after adding the new node,
 * even though the head of the list hasn't changed),
 * or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	size_t str_len;
	list_t *new_node, *current_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	for (str_len = 0; str[str_len]; str_len++)
		;

	new_node->len = str_len;
	new_node->next = NULL;
	current_node = *head;

	if (current_node == NULL)
	{
		*head = new_node;
	}

	else
	{
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}

	return (*head);
}