#include "monty.h"

/**
 * _push - add new node in the beginnig of the stack.
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *num = NULL;
	stack_t *new = NULL;

	if (dba->input[1] == NULL)
		__RETURN__("Error push NULL\n", "", "");
	else
		num = dba->input[1];

	if (is_number(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(num);
	add_dnodeint(stack, new);
}

/**
 * add_dnodeint - Add node in the first position
 * @stack: the header of de double linked list
 * @new: new
 *
 * Return: double linked list
 */

void add_dnodeint(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints all the values on the stack
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void) line_number;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack.
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an e empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
