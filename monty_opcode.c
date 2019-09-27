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
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(stack, dba->file);
		exit(EXIT_FAILURE);
	}
	else
		num = dba->input[1];

	if (is_number(num) == 0)
	{
		free_all(stack, dba->file);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_all(stack, dba->file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(num);
	add_dnodeint(stack, new);
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
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
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

/**
 * _swap - swaps the top two elements of the stack.
 * @stack: stack
 * @line_number: number of line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int num_n;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_all(stack, dba->file);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num_n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num_n;
}
