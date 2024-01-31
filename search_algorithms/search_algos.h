#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * struct listint_s - structure for singly linked list
 *
 * @n: an integer value stored in the node
 * @index: the index of the node within the list
 * @next: a pointer to the next node in the list
 */

typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;



/**
 * struct skiplist_s - structure for skip list
 *
 * @n: an integer value stored in the node
 * @index: the index of the node within the list
 * @next: a pointer to the next node in the list
 * @express: a pointer to the next node in the express lane
 *
 * a skip list is an augmented version of a singly linked list,
 * designed for faster searching;
 * each node has a pointer to the next node (like a standard linked list)
 * and an additional 'express' pointer to a further node, which allows
 * for skipping over some nodes, hence reducing the number of steps
 * required to traverse the list
 */

typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;



int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);


/* advances tasks */
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int _binary_search(int *array, size_t size, int value);
int *_advanced_binary(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);


/* functions needed for testing task 105 */
listint_t *create_list(int *array, size_t size);
void print_list(const listint_t *list);
void free_list(listint_t *list);


/* functions needed for testing task 106 */
void init_express(skiplist_t *list, size_t size);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);



#endif /* SEARCH_ALGOS_H */