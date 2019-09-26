#include "monty.h"
/**
 * myStartupFun - construct init function
 */
void myStartupFun(void)
{
	instruction_t func[] = {{"push", _push}, {"pall", _pall}, {NULL, NULL}};

	dba = malloc(sizeof(dba_t));
	if (!dba)
		exit(1);

	dba->func = malloc((sizeof(instruction_t) * 3) + 1);
	memcpy(dba->func, func, sizeof(func));

	dba->input = malloc(sizeof(char *) * 3);
	if (!dba->input)
	{
		perror("malloc");
		exit(1);
	}
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
	char *buf = NULL, *filename = NULL, *delim = "\n ", *new = NULL;
	size_t buf_size = 0;
	FILE *file;
	int i = 0, len = 0;
	unsigned int linenum = 0;
	stack_t *stack = NULL;

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
		new = buf, len = strlen(buf);
		linenum++;
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
			} i++;
		}
	} free(dba->input);
	return (0);
}
