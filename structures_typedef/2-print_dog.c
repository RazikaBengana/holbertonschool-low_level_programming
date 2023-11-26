#include "dog.h"

/**
 * print_dog - program that prints a struct dog
 *
 * if an element of d is NULL, print (nil) instead of this element -> (if name is NULL, print Name: (nil))
 * if d is NULL print nothing
 *
 * @d: a pointer to a struct dog variable that will be printed
 *
 * Return: nothing (void)
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		d->name = "(nil)";

	if (d->owner == NULL)
		d->owner = "(nil)";

	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}