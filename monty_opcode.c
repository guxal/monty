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
                printf("L%d: usage: push integer\n", line_number);
        new = malloc(sizeof(stack_t));
        if (!new)
                perror("malloc:");

        new->n = atoi(num);
        new->prev = NULL;
        new->next = *stack;
        if (*stack)
                (*stack)->prev = new;
        *stack = new;
}
