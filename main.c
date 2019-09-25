#include "monty.h"

/**
 * _push - add new node in the beginnig of the stack.
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	
}

/**
 * _pall - prints all the values on the stack
 * @stack: head of stack (double linked list).
 * @line_number: the number of the line.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	printf("david\n");
}
/**
 * main - Init the program, compile code for monty
 * @argc: number of arguments
 * @argv: the arguments
 *
 * Return: the program
 */

int main(int argc, char **argv)
{
	char *buf = NULL, *filename = NULL, *delim = NULL, *new = NULL;
	size_t buf_size = 0;
	FILE *file;
	int i = 0, len = 0;
	instruction_t func[] = { {"push", _push}, {"pall", _pall}, {NULL, NULL}};
	stack_t *stack = NULL;

	delim = "\n ";

	if (argc != 2)
	{
		perror("Error: no such file\n");
		return (1);
	}

	filename = argv[argc - 1];
	file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error: can't open file\n");
		return (1);
	}

	dba = malloc(sizeof(dba_t));
	if (!dba)
	{
		perror("malloc");
		return (1);
	}

	dba->input = malloc(sizeof(char *) * 3);
	if (!dba->input)
	{
		perror("malloc");
		return (1);
	}

	while (getline(&buf, &buf_size, file) > 0)
	{
		new = buf;

		len = strlen(buf);
		while ((new[i] == delim[0]) || (new[i] == delim[1]))
			i++;
		if (i == len)
			continue;

		dba->input[0] = strtok(buf, delim);
		dba->input[1] = strtok(NULL, delim);
		printf("%s %s\n", dba->input[0], dba->input[1]);

		i = 0;
		while (func[i].opcode != NULL)
		{
			if (strncmp(func[i].opcode, dba->input[0], strlen(dba->input[0])) == 0)
			{
				func[i].f(&stack, 1);
				break;
			}
			i++;
		}
	}

	free(dba->input);
	return (0);
}
