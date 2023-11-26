#include "function_pointers.h"

/**
 * array_iterator - program that executes a function given as a parameter on each element of an array
 *
 * this function takes an array, its size, and a function pointer as arguments;
 * if the array and the function pointer are not NULL, it iterates over each element of the array
 * and applies the function pointed to by `action` on each element;
 * the called function is responsible for performing an operation on the array elements
 *
 * @array: the pointer to the array
 * @size: the size of the array
 * @action: the pointer to the function that will be executed on each array element
 *
 * Return: nothing (void)
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int index;

	if (array == NULL || action == NULL)
		return;

	for (index = 0; index < size; index++)
		action(array[index]);
}