#include "3-calc.h"

/**
 * get_op_func - program that selects the correct arithmetic function to perform the operation asked by the user
 *
 * @s: the operator passed as argument to the program
 *
 * Return: a pointer to the function that corresponds to the operator given as a parameter
 * (for example: get_op_func("+") should return a pointer to the function op_add);
 * if s does not match any of the 5 expected operators (+, -, *, /, %), return NULL
 */

int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].op)
	{
		if (*(ops[i].op) == *s)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}