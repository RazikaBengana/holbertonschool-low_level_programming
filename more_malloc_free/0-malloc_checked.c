#include "main.h"

/**
 * malloc_checked - program that allocates memory using malloc
 *
 * the malloc_checked function attempts to allocate memory of size 'b' using malloc.
 * if malloc fails, the malloc_checked function should cause normal process termination with a status value of 98
 *
 * @b: the size of the memory to allocate
 *
 * Return: a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{

	void *ptr_allocated_memory;

	ptr_allocated_memory = malloc(b);

	if (ptr_allocated_memory == NULL)
		exit(98);

	return (ptr_allocated_memory);
}