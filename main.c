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
	FILE *file;

	if (argc != 2)
	{
		perror("Error: no such file\n");
		return(1);
	}

	filename = argv[argc - 1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error: can't open file\n");
		return (1);
	}

	return (0);
}

