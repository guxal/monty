#ifndef _MONTY_H_
#define _MONTY_H_

/*--- C libs ---*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- Start ---*/
void myStartupFun(void) __attribute__ ((constructor));

/*--- Structs ---*/
typedef int bool;
#define true 1
#define false 0

#define __RETURN__(str, value) \
	(__extension__ \
	 ({ \
	  fprintf(stderr, "%s", str); \
	  value; \
	  }))
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct dba_s - global database for monty
 * @input: lines of the file input[0] - the opcode, input[1] - integer
 * @func: is the struct opcodes
 */

typedef struct dba_s
{
	char **input;
	instruction_t *func;
} dba_t;

/*--- Global ---*/
extern dba_t *dba;
dba_t *dba;

/*--- Integer ---*/
int is_number(char *num);

/*--- add in stack ---*/
void _push(stack_t **, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void add_dnodeint(stack_t **, stack_t *);

#endif
