#include "hash_tables.h"

/**
 * hash_table_get - program that retrieves the value associated with a given key in a hash table
 *
 * this function searches for a given key in the hash table 'ht';
 * it computes the index in the hash table's array where the key-value pair might be stored
 * using the key_index function;
 * it then iterates through the linked list at that index to find the desired key
 *
 * @ht: a pointer to the hash table in which to search for the key
 * @key: the key for which to search in the hash table
 *
 * Return: the value associated with the key, or NULL if the key is not found
 *         or if either 'ht' or 'key' is NULL
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int indexForKey;
	hash_node_t *currentNode;

	if (ht == NULL || key == NULL)
		return (NULL);

	indexForKey = key_index((const unsigned char *)key, ht->size);
	currentNode = ht->array[indexForKey];

	while (currentNode)
	{
		if (strcmp(currentNode->key, key) == 0)
			return (currentNode->value);

		currentNode = currentNode->next;
	}

	return (NULL);
}
