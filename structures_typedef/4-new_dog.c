#include "dog.h"

/**
 * *new_dog - program that creates a new dog structure
 *
 * we have to allocate memory for a new dog_t structure, initializes its members,
 * and returns a pointer to the new structure
 * we have to store a copy of 'name' and 'owner'
 *
 * @name: a pointer to the name of the dog
 * @age: the age of the dog
 * @owner: a pointer to the owner of the dog
 *
 * Return: a pointer to the newly created dog_t structure, or NULL if the function fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	int name_length, owner_length;
	int index;
	dog_t *dog;

	dog = (dog_t *)malloc(sizeof(dog_t));

	if (dog == NULL)
		return (NULL);

	name_length = owner_length = 0;

	while (name[name_length++])
		;

	while (owner[owner_length++])
		;

	dog->name = malloc(name_length * sizeof(dog->name));

	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	for (index = 0; index <= name_length; index++)
		dog->name[index] = name[index];

	dog->age = age;
	dog->owner = malloc(owner_length * sizeof(dog->owner));

	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	for (index = 0; index <= owner_length; index++)
		dog->owner[index] = owner[index];

	return (dog);
}