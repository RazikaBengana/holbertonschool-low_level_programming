#ifndef LISTS_H
#define LISTS_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/**
 * struct dlistint_s - doubly linked list node structure
 *
 * Description: this structure is defined for a node in a doubly linked list
 *
 * @n: the integer value stored in the node
 * @prev: a pointer to the previous node in the doubly linked list
 * @next: a pointer to the next node in the doubly linked list
 */

typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;



size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
int sum_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

/* advanced tasks */
int isPalindrome(int num);
int countDigits(int value);
int power(int base, int exponent);
int calculateValue1(int length);
int calculateValue2(char *str, int length);
int calculateValue3(char *str, int length);
int calculateValue4(char *str, int length);
int calculateValue5(char *str, int length);
int calculateValue6(char character);


#endif /* LISTS_H */