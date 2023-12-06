#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *input;

	while (1)
	{
		input = prompt_user();

		if (input == NULL)
		{
			fprintf(stderr, "Error reading input\n");
			exit(EXIT_FAILURE);
		}

		if (execute_command(input) == -1)
		{
			/* Handle error in execute_command */
		}

		free(input);
	}

	return (0);
}

