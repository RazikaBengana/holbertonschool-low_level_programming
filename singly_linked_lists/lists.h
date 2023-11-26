#ifndef LISTS_H
#define LISTS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/**
 * struct list_s - singly linked list node structure
 *
 * @str: a dynamically allocated string held by the node (malloc'ed string)
 * @len: the length of the string
 * @next: a pointer to the next node in the linked list
 *
 * this structure defines a node for a singly linked list;
 * each node holds a dynamically allocated string (@str),
 * the length of the string (@len), and a pointer to the next node (@next);
 * the linked list is formed by connecting nodes through the @next pointers
 */

typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;


/* _putchar function (if needed) */
int _putchar(char c);

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

/* advanced tasks */
void printfirst(void);


#endif /* LISTS_H */