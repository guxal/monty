#include "monty.h"
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


