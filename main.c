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
	char *buf = NULL;
	char *filename;
	size_t buf_size = 0;

	if (argc != 2)
	{
		perror("Error: no such file\n");
		return(1);
	}

	filename = argv[argc - 1];
	printf("%s\n", filename);

	return (0);
}

