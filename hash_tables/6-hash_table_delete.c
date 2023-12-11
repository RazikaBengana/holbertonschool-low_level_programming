#include "hash_tables.h"

/**
 * hash_table_delete - program that frees and deletes a hash table
 *
 * this function iterates through each slot in the hash table and frees the memory
 * allocated for each node in the linked list at that slot;
 * it specifically frees the 'key' and 'value' of each node before freeing the node itself;
 * after freeing all nodes in all slots, it frees the array of the hash table and then the
 * hash table structure itself, effectively deleting the entire hash table from memory
 *
 * @ht: a pointer to the hash table that is to be deleted
 *
 * Return: nothing (void)
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *currentNode = NULL, *tempNode = NULL;
	unsigned long int index;

	if (!ht)
		return;

	for (index = 0; index < ht->size; index++)
	{
		for (currentNode = ht->array[index]; currentNode;)
		{
			free(currentNode->value);
			free(currentNode->key);
			tempNode = currentNode;
			currentNode = currentNode->next;
			free(tempNode);
		}
	}
	free(ht->array);
	free(ht);
}
