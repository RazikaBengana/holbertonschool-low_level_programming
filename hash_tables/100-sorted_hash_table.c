#include "hash_tables.h"

/**
 * print_ht - program that prints the key-value pairs at the head and tail of a sorted hash table
 *
 * this function is used to display the first (head) and last (tail) elements of a sorted hash table,
 * helping in understanding the state of the hash table, especially for debugging purposes;
 * it prints the key-value pair stored at the head (`shead`) and tail (`stail`) nodes of the hash table;
 * if the hash table is empty or if `shead` or `stail` are NULL, the behavior of this function
 * depends on how these conditions are handled in the rest of the program
 *
 * @ht: a pointer to the sorted hash table whose head and tail elements are to be printed
 *
 * Return: nothing (void)
 */

void print_ht(shash_table_t *ht)
{
	printf("SHEAD: [%s]:[%s]\n", ht->shead->key, ht->shead->value);
	printf("STAIL: [%s]:[%s]\n", ht->stail->key, ht->stail->value);
}



/**
 * shash_table_create - program that creates a new sorted hash table
 *
 * this function allocates memory for a new sorted hash table and its internal array;
 * the size of the hash table (number of slots in the internal array) is specified by the 'size' parameter;
 * memory allocation is done using calloc to ensure that all elements are initialized to NULL;
 * this initialization is crucial for indicating that the hash table slots are empty upon creation;
 * if the allocation fails at any stage (either for the hash table structure or its internal array),
 * any allocated memory is freed to prevent memory leaks, and the function returns NULL
 *
 * @size: the number of slots in the sorted hash table --> it determines the size of the internal array
 *
 * Return: a pointer to the newly created sorted hash table if successful, or NULL if memory allocation fails
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_sorted_hash_table;

	if (size == 0)
		return (NULL);

	new_sorted_hash_table = calloc(1, sizeof(shash_table_t));

	if (new_sorted_hash_table == NULL)
		return (NULL);

	new_sorted_hash_table->size = size;
	new_sorted_hash_table->array = calloc(size, sizeof(shash_node_t *));

	if (new_sorted_hash_table->array == NULL)
	{
		free(new_sorted_hash_table);
		return (NULL);
	}

	return (new_sorted_hash_table);
}



/**
 * new_snode - program that creates a new sorted hash node
 *
 * this function allocates memory for a new sorted hash node and initializes it with
 * the provided key and value;
 * if memory allocation fails at any step (for the node itself, or for the key or value strings),
 * it performs necessary cleanup by freeing any allocated resources before returning NULL
 *
 * @key: the key string to be stored in the node
 * @value: the value string to be associated with the key
 *
 * Return: a pointer to the newly created node if successful, or NULL if any memory allocation fails
 */

shash_node_t *new_snode(const char *key, const char *value)
{
	shash_node_t *newNode;

	newNode = calloc(1, sizeof(shash_node_t));

	if (!newNode)
		return (NULL);

	newNode->key = strdup(key);

	if (!newNode->key)
	{
		free(newNode);
		return (NULL);
	}

	newNode->value = strdup(value);

	if (!newNode->value)
	{
		free(newNode->key);
		free(newNode);
		return (NULL);
	}

	return (newNode);
}



/**
 * shash_table_sort - program that sorts a node into a sorted hash table
 *
 * this function inserts a given node ('new_node') into a sorted hash table ('sorted_hash_table')
 * maintaining the order based on the key of the nodes;
 * the sorted hash table is doubly linked, allowing for efficient insertion in sorted order;
 * if the new node's key is less than the key of the head node, it becomes the new head;
 * otherwise, the function finds the appropriate position for the new node to maintain order;
 * the function handles updating the links of adjacent nodes to include the new node in the hash table;
 * if the hash table or the new node is NULL, the function does nothing
 *
 * @sorted_hash_table: the sorted hash table where the new node is to be inserted
 * @new_node: the new node to be inserted into the hash table
 *
 * Return: nothing (void)
 */

void shash_table_sort(shash_table_t *sorted_hash_table, shash_node_t *new_node)
{
	shash_node_t *current_node;

	if (!sorted_hash_table)
		return;

	current_node = sorted_hash_table->shead;

	if (!current_node || strcmp(new_node->key, current_node->key) < 0)
	{
		new_node->snext = current_node;
		sorted_hash_table->shead = new_node;

		if (current_node)
			current_node->sprev = new_node;

		else
			sorted_hash_table->stail = new_node;

		return;
	}

	while (current_node->snext && strcmp(new_node->key, current_node->snext->key) >= 0)
		current_node = current_node->snext;

	new_node->sprev = current_node;
	new_node->snext = current_node->snext;

	if (current_node->snext)
		current_node->snext->sprev = new_node;

	else
		sorted_hash_table->stail = new_node;

	current_node->snext = new_node;
}



/**
 * shash_table_set - program that inserts or updates a key-value pair in a sorted hash table
 *
 * this function is designed to insert or update a key-value pair in a sorted hash table;
 * if the key already exists in the hash table, the function updates its associated value;
 * otherwise, it adds a new node with the key-value pair to the hash table;
 * the hash table maintains its elements in a sorted order
 *
 * @hashTable: a pointer to the sorted hash table
 * @key: the key associated with the value to be inserted or updated
 * @value: the value to be associated with the key
 *
 * Return: 1 if the operation is successful, 0 if it fails (due to memory allocation failure or null parameters)
 */

int shash_table_set(shash_table_t *hashTable, const char *key, const char *value)
{
	shash_node_t *newNode = NULL, *currentNode;
	unsigned long int hashIndex;

	if (!hashTable || !key || !*key || !value)
		return (0);

	hashIndex = key_index((const unsigned char *)key, hashTable->size);
	currentNode = hashTable->array[hashIndex];

	while (currentNode)
	{
		if (!strcmp(key, currentNode->key))
		{
			char *newValue = strdup(value);

			if (!newValue)
				return (0);

			free(currentNode->value);
			currentNode->value = newValue;
			return (1);
		}
		currentNode = currentNode->next;
	}

	newNode = new_snode(key, value);

	if (!newNode)
		return (0);

	newNode->next = hashTable->array[hashIndex];
	hashTable->array[hashIndex] = newNode;
	shash_table_sort(hashTable, newNode);

	return (1);
}



/**
 * shash_table_get - program that retrieves a value from a sorted hash table based on a given key
 *
 * this function searches for a specific key in a sorted hash table and returns
 * the associated value;
 * it calculates the index where the key is expected to be located using a hash function;
 * it then iterates through the linked list at that index in the hash table, comparing
 * each node's key with the target key;
 * if a matching key is found, the associated value is returned;
 * if the key is not found or if the hash table or key is NULL, the function returns NULL
 *
 * @ht: a pointer to the sorted hash table
 * @key: the key string whose associated value is to be retrieved
 *
 * Return: the value associated with the key, or NULL if the key is not found or the hash table/key is NULL
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (!strcmp(node->key, key))
			return (node->value);

		node = node->next;
	}
	return (NULL);
}



/**
 * shash_table_print - program that prints the contents of a sorted hash table
 *
 * this function traverses a sorted hash table and prints its contents in the format '{'key': 'value', ...}';
 * the function checks if the hash table exists before attempting to print;
 * it iterates through each node in the table, printing the key-value pairs;
 * a comma is added between the pairs for readability;
 * the function handles an empty or non-existing hash table gracefully by not printing any content
 *
 * @ht: a pointer to the sorted hash table to be printed
 *
 * Return: nothing (void)
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;
	size_t is_first_printed = 0;

	if (!ht)
		return;

	printf("{");
	current_node = ht->shead;

	while (current_node)
	{
		if (is_first_printed)
			printf(", ");

		printf("'%s': '%s'", current_node->key, current_node->value);
		is_first_printed++;
		current_node = current_node->snext;
	}
	printf("}\n");
}



/**
 * shash_table_print_rev - program that prints a sorted hash table in reverse order
 *
 * this function iterates over the elements of a sorted hash table ('ht') in reverse order,
 * starting from the tail;
 * it prints each key-value pair in the format "'key': 'value'";
 * pairs are separated by a comma and a space;
 * the function handles empty or NULL hash tables gracefully by not performing any operations;
 * the 'printed' variable tracks if any pairs have been printed to ensure correct formatting (no leading comma)
 *
 * @ht: a pointer to the sorted hash table to be printed
 *
 * Return: nothing (void)
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *currentNode;
	size_t isPrintingStarted = 0;

	if (!ht)
		return;

	printf("{");
	currentNode = ht->stail;

	while (currentNode)
	{
		if (isPrintingStarted)
			printf(", ");

		printf("'%s': '%s'", currentNode->key, currentNode->value);
		isPrintingStarted++;
		currentNode = currentNode->sprev;
	}
	printf("}\n");
}



/**
 * shash_table_delete - program that frees and deletes a sorted hash table
 *
 * this function is responsible for deallocating all the memory used by a sorted hash table;
 * it iterates over each slot of the hash table array;
 * for each slot, it traverses the linked list of nodes, freeing the memory allocated for the key
 * and value of each node before freeing the node itself;
 * after all nodes in all slots have been freed, the function deallocates the array of the hash table
 * and finally the hash table structure itself;
 * if the hash table pointer is NULL, the function does nothing
 *
 * @ht: a pointer to the sorted hash table to be deleted
 *
 * Return: nothing (void)
 */

void shash_table_delete(shash_table_t *ht)
{
	unsigned long slotIndex = 0;
	shash_node_t *currentNode, *nextNode;

	if (!ht)
		return;

	for (slotIndex = 0; slotIndex < ht->size; slotIndex++)
	{
		currentNode = ht->array[slotIndex];

		while (currentNode)
		{
			nextNode = currentNode->next;
			free(currentNode->key);
			free(currentNode->value);
			free(currentNode);
			currentNode = nextNode;
		}
	}
	free(ht->array);
	free(ht);
}
