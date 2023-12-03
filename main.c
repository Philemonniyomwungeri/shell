#include "hsh.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *input;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("($) ");
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			free(input);
			exit(EXIT_FAILURE);
		}

		if (read > 1)
		{
			input[read - 1] = '\0'; /* Remove newline character */
			if (execute_command(parse_input(input)) == -1)
				break;
		}
	}

	free(input);
	return (0);
}

