#include "monty.h"

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
	char **copy;
	size_t buf_size = 0;
	FILE *file;
	int i = 0, len = 0;

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

	copy = malloc(sizeof(char *) * 3);
	if (!copy)
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

		copy[0] = strtok(buf, delim);
		copy[1] = strtok(NULL, buf);
	}
	printf("%s\n%s", copy[0], copy[1]);
	return (0);
}
