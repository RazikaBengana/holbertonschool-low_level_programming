#include "function_pointers.h"

/**
 * print_name - program that prints a name
 *
 * this function takes a name and a function pointer as arguments;
 * if the name and function pointer are not NULL, it calls the function
 * pointed to by f and passes the name as an argument;
 * the called function is responsible for printing or processing the name
 *
 * @name: the name to be printed
 * @f: a function pointer to a function that takes a character pointer as an argument
 *
 * Return: nothing (void)
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}