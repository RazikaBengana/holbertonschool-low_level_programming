#include "hash_tables.h"

/**
 * key_index - program that calculates the index for a key in a hash table
 *
 * this function takes a key and the size of a hash table as inputs;
 * it first uses the 'hash_djb2' function to generate a hash value for the given key;
 * the generated hash value is then modulo divided by the size of the hash table;
 * the result of this division is the index where the key-value pair should be stored in the hash table;
 * this process helps in evenly distributing the keys across the available space in the hash table,
 * reducing the chance of collisions (where multiple keys generate the same index)
 *
 * @key: a pointer to the unsigned char data representing the key
 * @size: the size of the array of the hash table (number of slots available)
 *
 * Return: the calculated index position within the hash table where the key-value pair
 *         associated with the given key should be stored
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}