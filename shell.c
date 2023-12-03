#include "hsh.h"

/**
 * execute_command - Execute a command
 * @args: Array of arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	pid_t child_pid;
	int status;

	if (!args || !args[0])
		return (0);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			print_error(args[0], "not found", 127);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
	}

	free_array(args);
	return (0);
}

/**
 * parse_input - Parse input into an array of arguments
 * @input: User input
 *
 * Return: Array of arguments
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token;
	int i = 0;

	args = malloc(BUFSIZE * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}

/**
 * _strlen - Calculate the length of a string
 * @s: Input string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * free_array - Free the memory allocated for an array of strings
 * @array: Array to be freed
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
		free(array[i]);

	free(array);
}

/**
 * print_error - Print an error message
 * @program: Name of the program
 * @message: Error message
 * @status: Exit status
 */
void print_error(char *program, char *message, int status)
{
	fprintf(stderr, "%s: %s: %s\n", program, message, strerror(status));
	exit(status);
}

