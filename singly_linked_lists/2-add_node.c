#include "lists.h"

/**
 * *add_node - program that adds a new node at the beginning of a linked list (list_t)
 *
 * str needs to be duplicated
 *
 * @head: a pointer to a pointer to the head of the linked list
 * @str: the string that has to be stored in the new node
 *
 * Return: the address of the new element (the new head of the list),
 * or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	unsigned int str_len;
	list_t *new_node;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	for (str_len = 0; str[str_len]; str_len++)
		;
	new_node->len = str_len;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}