#include "dog.h"

/**
 * init_dog - program that initializes a variable of type struct dog
 *
 * @d: a pointer to a struct dog variable that will be initialized
 * @name: a pointer to a character (char *) representing the name of the dog
 * @age: a float representing the age of the dog
 * @owner: a pointer to a character (char *) representing the owner of the dog
 *
 * Return: nothing (void)
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}