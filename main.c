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
	dprintf(STDERR_FILENO, string, str, str1);
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
		__RETURN__("Error: malloc failed", "", "");

	dba->func = malloc((sizeof(instruction_t) * 4) + 1);
	memcpy(dba->func, func, sizeof(func));

	dba->input = malloc(sizeof(char *) * 3);
	if (!dba->input)
		__RETURN__("Error: malloc failed", "", "");
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
	int i = 0, len = 0, _continue;
	unsigned int linenum = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		__RETURN__("USAGE: monty file\n", "", "");
	filename = argv[argc - 1], file = fopen(filename, "r");
	if (file == NULL)
		__RETURN__("Error: can't open file %s\n", filename, "");
	myStartupFun();
	while (getline(&buf, &buf_size, file) > 0)
	{
		new = buf, len = strlen(buf), _continue = false;
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
			if (strcmp(dba->func[i].opcode, dba->input[0]) == 0)
			{
				dba->func[i].f(&stack, linenum), _continue = true;
				break;
			} i++;
		}
		if (_continue)
			continue;
		fprintf(stderr, "L%d: unknown instruction %s\n", linenum, dba->input[0]);
		return (1);
	} free(dba->input);
	return (0);
}
