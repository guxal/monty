#include "monty.h"

/**
 * is_number - verify if the input[1] is a number.
 * @num: input[1].
 *
 * Return: 1 if true and 0 if false.
 */

int is_number(char *num)
{
	int i;

	for (i = 0; num[i] != 0; i++)
	{
		if (((num[i] > 47) && (num[i] < 58)) || num[i] == 45)
			continue;
		else
			return (0);
	}
	return (1);
}
