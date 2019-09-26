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
		printf("Error push NULL\n");
	else
		num = dba->input[1];

	if (is_number(num) == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(1);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
		perror("malloc:");
	
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

        tmp = *stack;
        while (tmp)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}
