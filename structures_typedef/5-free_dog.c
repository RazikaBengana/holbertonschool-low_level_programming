#include "dog.h"

/**
 * free_dog - program that frees dogs
 *
 * free the memory allocated for the members of a dog structure,
 * including the name and owner strings, and finally frees the memory
 * allocated for the dog structure itself
 *
 * @d: a pointer to the dog structure to be freed
 *
 * Return: nothing (void)
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}