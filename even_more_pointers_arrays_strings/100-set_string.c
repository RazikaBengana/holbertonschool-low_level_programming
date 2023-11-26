#include "main.h"

/**
 * set_string - program that sets the value of a pointer to a char
 *
 * this function updates a string pointer to point to a new string
 *
 * @s: a pointer to a pointer that will be updated
 * @to: the new string to which the pointer should point
 *
 * Return: nothing (void)
 */

void set_string(char **s, char *to)
{
	*s = to;
}