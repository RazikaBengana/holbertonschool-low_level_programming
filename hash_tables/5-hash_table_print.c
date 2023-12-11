#include "hash_tables.h"

/**
 * hash_table_print - program that prints the contents of a hash table
 *
 * this function iterates over each slot in the hash table and prints the key-value
 * pairs contained in it;
 * the output is formatted as a dictionary in the style of Python dictionaries;
 * if a slot contains more than one key-value pair due to collision, each pair is printed;
 * the function handles an empty hash table and will not print anything if the hash table
 * pointer is NULL;
 *
 * we should print the key/value in the order that they appear in the array of hash table:
 * --> order: array, list
 *
 * @ht: a pointer to the hash table to be printed
 *
 * Return: nothing (void)
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *node = NULL;
	char *delimiter = "";

	if (!ht)
		return;

	printf("{");

	for (index = 0; index < ht->size; index++)
	{
		node = ht->array[index];

		for (; node; node = node->next)
		{
			printf("%s'%s': '%s'", delimiter, node->key, node->value);
			delimiter = ", ";
		}
	}
	printf("}\n");
}
