#include "monty.h"
/**
 * _mod - module compute the rest of the division
 * @stack: the stack
 * @line_number: number of the line error
 **/

void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mod;
}

