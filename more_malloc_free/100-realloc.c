#include "main.h"

/**
 * _realloc - program that reallocates a memory block using malloc and free
 *
 * the contents will be copied to the newly allocated space, in the range from the start of ptr
 * up to the minimum of the old and new sizes;
 * if new_size > old_size, the 'added' memory should not be initialized;
 * If new_size == old_size, we do not do anything and return ptr;
 * if ptr is NULL, then the call is equivalent to malloc(new_size), for all values
 * of old_size and new_size;
 * if new_size is equal to zero, and ptr is not NULL, then the call is equivalent
 * to free(ptr), and we return NULL;
 * we do not have to forget to free ptr when it makes sense
 *
 * @ptr: a pointer to the original memory block (the memory previously allocated)
 * @old_size: the size of the original memory block in bytes (of the allocated space for ptr)
 * @new_size: the desired size of the reallocated memory block in bytes (the new memory block)
 *
 * Return: if reallocation is successful, returns a pointer to the reallocated memory block;
 * if reallocation fails, returns NULL and the original block remains unchanged
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_mem;
	char *original_ptr, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_mem = malloc(new_size);

		if (new_mem == NULL)
			return (NULL);

		return (new_mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	original_ptr = ptr;
	new_mem = malloc(sizeof(*original_ptr) * new_size);

	if (new_mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = new_mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *original_ptr++;

	free(ptr);
	return (new_mem);
}