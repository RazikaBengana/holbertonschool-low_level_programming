#include "hash_tables.h"

/**
 * hash_table_set - program that adds or updates a key-value pair in a hash table
 *
 * this function inserts a new key-value pair into the hash table or updates
 * the value of an existing key;
 * it handles collisions using chaining;
 * if the key already exists in the hash table, its value is updated;
 * otherwise, a new node is created and added to the hash table;
 *
 * 'key' can not be an empty string, but 'value' can be an empty string;
 * in case of collision, we have to add the new node at the beginning of the list
 *
 * @ht: a pointer to the hash table where the key-value pair should be set
 * @key: the key associated with the value to set or update in the hash table
 * @value: the value to be associated with the key (it must be duplicated)
 *
 * Return: 1 if the key-value pair was added or updated successfully, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newNode;
	char *copiedValue;
	unsigned long int index, currentPosition;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	copiedValue = strdup(value);

	if (copiedValue == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (currentPosition = index; ht->array[currentPosition]; currentPosition++)
	{
		if (strcmp(ht->array[currentPosition]->key, key) == 0)
		{
			free(ht->array[currentPosition]->value);
			ht->array[currentPosition]->value = copiedValue;
			return (1);
		}
	}

	newNode = malloc(sizeof(hash_node_t));

	if (newNode == NULL)
	{
		free(copiedValue);
		return (0);
	}

	newNode->key = strdup(key);

	if (newNode->key == NULL)
	{
		free(newNode);
		return (0);
	}

	newNode->value = copiedValue;
	newNode->next = ht->array[index];
	ht->array[index] = newNode;

	return (1);
}
