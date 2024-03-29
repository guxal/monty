#include "monty.h"

/**
 * _nop - doesn’t do anything.
 * @stack: the double pointer.
 * @line_number: the line of command
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _add - add two numbers from the top of that stack
 * @stack: the stack
 * @line_number: the line number
 * Return: none
 **/
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}
/**
 * _sub - substract the top element of the second stop
 * @stack: the stack
 * @line_number: the line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = sub;
}
/**
 * _div - divides the top stack elements
 * @stack: the stack
 * @line_number: the line number
 **/
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = div;
}
/**
 * _mul - multiplies the top in the stack
 * @stack: the stack
 * @line_number: the line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mul;
}
