#include "monty.h"
/**
 * __RETURN__ - return posix
 * @string: string
 * @str: param
 * @str1: param
 * Return: exit
 **/
void __RETURN__(char *string, char *str, char *str1)
{
	fprintf(stderr, string, str, str1);
	exit(EXIT_FAILURE);
}
/**
 * myStartupFun - construct init function
 */
void myStartupFun(void)
{
	instruction_t func[] = { {"push", _push}, {"pall", _pall},
		{"pint", _pint}, {NULL, NULL}};

	dba = malloc(sizeof(dba_t));
	if (!dba)
		__RETURN__("Error: malloc failed\n", "", "");

	dba->func = malloc((sizeof(instruction_t) * 4) + 1);
	if (!dba->func)
	{
		free(dba);
		__RETURN__("Error: malloc failed\n", "", "");
	}
	memcpy(dba->func, func, sizeof(func));

	dba->input = malloc(sizeof(char *) * 3);
	if (!dba->input)
	{
		free(dba);
		free(dba->func);
		__RETURN__("Error: malloc failed\n", "", "");
	}
}

/**
 * free_all - free all
 * @stack: stack
 * @file: file
 **/
void free_all(stack_t **stack, FILE *file)
{
	stack_t *tmp;

	if (dba != NULL)
	{
		if (dba->input != NULL)
			free(dba->input);
		free(dba->func);
	}
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
	free(tmp);
	free(*stack);
	free(dba->line);
	free(dba);
	fclose(file);
}
/**
 * UNKNOW_ERROR - dprintf error
 * @linenum: number line error
 * @input: opcode instruction
 */
void UNKNOW_ERROR(unsigned int linenum, char *input)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
			linenum, input);
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
	char *filename = NULL, *delim = "\n ";
	size_t buf_size = 0;
	FILE *file;
	int i = 0, len = 0, _continue;
	unsigned int linenum = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		__RETURN__("USAGE: monty file\n", "", "");
	filename = argv[argc - 1], file = fopen(filename, "r");
	if (file == NULL)
		__RETURN__("Error: Can't open file %s\n", filename, "");
	myStartupFun(), dba->file = file;
	while (getline(&dba->line, &buf_size, file) > 0)
	{
		len = strlen(dba->line), _continue = false, linenum++;
		while ((dba->line[i] == delim[0]) || (dba->line[i] == delim[1]))
			i++;
		if (i == len)
			continue;
		dba->input[0] = strtok(dba->line, delim), dba->input[1] = strtok(NULL, delim);
		i = 0;
		while (dba->func[i].opcode != NULL)
		{
			if (strcmp(dba->func[i].opcode, dba->input[0]) == 0)
			{
				dba->func[i].f(&stack, linenum), _continue = true;
				break;
			} i++;
		}
		if (_continue)
			continue;
		UNKNOW_ERROR(linenum, dba->input[0]), free_all(&stack, file);
		exit(EXIT_FAILURE);
	} free_all(&stack, file);
	return (EXIT_SUCCESS);
}
