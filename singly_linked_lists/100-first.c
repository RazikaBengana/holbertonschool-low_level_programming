#include "lists.h"

void printfirst(void) __attribute__ ((constructor));

/**
 * printfirst - constructor function that prints a message before main
 *
 * this function is marked with the __attribute__((constructor)) attribute,
 * which ensures that it is automatically executed before the main function
 * when the program starts;
 * it prints a message to the standard output
 *
 * Return: nothing (void)
 */

void printfirst(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}