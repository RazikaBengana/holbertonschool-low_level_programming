#include "../search_algos.h"

/**
 * print_list - program that prints the elements of a linked list
 *
 * this function traverses a singly linked list and prints the index and value
 * of each node in the format "Index[<index>] = [<value>]";
 * it continues until it reaches the end of the list
 *
 * @list: a pointer to the head of the listint_t linked list
 *
 * Return: nothing (void)
 */

void print_list(const listint_t *list)
{
	printf("List :\n");

	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}