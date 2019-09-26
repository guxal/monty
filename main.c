#include "monty.h"

/* implementation of myStartupFun */
void myStartupFun (void)
{
	instruction_t func[] = {{"push", _push}, {NULL, NULL}};

	dba = malloc(sizeof(dba_t));
	if(!dba)
		exit(1);

	dba->func = func;

	dba->input = malloc(sizeof(char *) * 3);
	if (!dba->input)
	{
		perror("malloc");
		exit (1);
	}
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
	unsigned int linenum = 0;
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



	while (getline(&buf, &buf_size, file) > 0)
	{
		new = buf;
		linenum++;
		len = strlen(buf);
		while ((new[i] == delim[0]) || (new[i] == delim[1]))
			i++;
		if (i == len)
			continue;

		dba->input[0] = strtok(buf, delim);
		dba->input[1] = strtok(NULL, delim);
		i = 0;
		while (dba->func[i].opcode != NULL)
		{
			if (strncmp(dba->func[i].opcode, dba->input[0], strlen(dba->input[0])) == 0)
			{
				dba->func[i].f(&stack, linenum);
				break;
			}
			i++;
		}
	}

	free(dba->input);
	return (0);
}
