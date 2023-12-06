#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *input;

	while (1)
	{
		input = prompt_user();
		if (input == NULL)
		{
			/* Handle error in prompt_user */
			return (EXIT_FAILURE);
		}

		if (execute_command(input) == -1)
		{
			/* Handle error in execute_command */
			return (EXIT_FAILURE);
		}

		/* Free dynamically allocated memory for input */
		free(input);
	}

	return (EXIT_SUCCESS);
}

