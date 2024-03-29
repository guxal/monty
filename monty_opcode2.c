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
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mod;
}

/**
 * _pchar - print char ascii
 * @stack: the stack
 * @line_number: number of the line error
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar(10);
}

/**
 * _pstr - print string
 * @stack: the stack
 * @line_number: number of the line error
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
		putchar(10);
	else
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->n <= 0 || tmp->n > 127)
				break;
			putchar(tmp->n);
			tmp = tmp->next;
		}
		putchar(10);
	}
}

/**
 * _rotl - rotates the stack top to bottom
 * @stack: the stack
 * @line_number: number of the line error
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	int end;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		end = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = end;
	}
}

/**
 * _rotr - rotates the stack bottom to top
 * @stack: the stack
 * @line_number: number of the line error
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}
