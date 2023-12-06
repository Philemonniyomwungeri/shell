#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for the program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1) /* An error occurred */
		{
			perror("getline");
			break;
		}

		if (read == 1 && line[0] == '\n') /* Reached end-of-file (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		printf("%s", line);
	}

	free(line);
	return (0);
}

