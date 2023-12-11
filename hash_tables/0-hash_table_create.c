#include "hash_tables.h"

/**
 * hash_table_create - program that creates a hash table
 *
 * this function dynamically allocates memory for a new hash table and initializes its contents;
 * each slot of the hash table's array is set to NULL
 *
 * @size: the size of the hash table to be created (the number of slots in the hash table)
 *
 * Return: a pointer to the newly created hash table, or NULL if memory allocation fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int index;
	hash_table_t *new_hash_table;

	new_hash_table = malloc(sizeof(hash_table_t));

	if (new_hash_table == NULL)
		return (NULL);

	new_hash_table->size = size;
	new_hash_table->array = malloc(sizeof(hash_node_t *) * size);

	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}

	for (index = 0; index < size; index++)
		new_hash_table->array[index] = NULL;

	return (new_hash_table);
}
