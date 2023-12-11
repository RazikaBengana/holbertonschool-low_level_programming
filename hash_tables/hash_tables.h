#ifndef HASH_TABLES_H
#define HASH_TABLES_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * struct hash_node_s - structure representing a node in a hash table
 *
 * @key: a pointer to a string representing the key of the node;
 *       the key is unique in the hash table
 * @value: a pointer to a string representing the value associated with the key
 * @next: a pointer to the next node in the hash table, used for handling collisions
 */

typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;



/**
 * struct hash_table_s - structure representing the hash table data structure (the hash table itself)
 *
 * @size: the size of the array of the hash table, typically representing the number of buckets
 * @array: a pointer to an array of pointers to 'hash_node_t', representing the buckets of the hash table;
 *         each cell of this array is a pointer to the first node of a linked list, because we want our
 *         hash table to use a "chaining collision" handling
 */

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;



hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);



/* advanced tasks */


/**
 * struct shash_node_s - structure representing a node in a sorted hash table
 *
 * @key: a pointer to a string representing the key of the node;
 *       the key is unique in the hash table
 * @value: the value corresponding to the key
 * @next: a pointer to the next node of the list for hash table chaining
 * @sprev: a pointer to the previous node for maintaining sorted order
 * @snext: a pointer to the next node for maintaining sorted order
 */

typedef struct shash_node_s
{
    char *key;
    char *value;
    struct shash_node_s *next;
    struct shash_node_s *sprev;
    struct shash_node_s *snext;
} shash_node_t;



/**
 * struct shash_table_s - structure representing a sorted hash table data structure
 *
 * @size: the size of the array of the hash table
 * @array: an array of pointers to 'shash_node_t' for the buckets;
 *         each cell of this array is a pointer to the first node of a linked list,
 *         because we want our hash table to use a "chaining collision" handling
 * @shead: a pointer to the head (start) of the sorted linked list
 * @stail: a pointer to the tail (end) of the sorted linked list
 */

typedef struct shash_table_s
{
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;



shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);



#endif /* HASH_TABLES_H */