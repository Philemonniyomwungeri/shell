#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

        /* Free dynamically allocated memory for input */
        free(input);
    }
	return (0);
}

#define BUFFER_SIZE 1024

/**
 * prompt_user - Display a prompt and wait for user input.
 *
 * Return: A dynamically allocated string containing the user input.
 */
char *prompt_user(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    printf("#cisfun$ ");
    getline(&buffer, &bufsize, stdin);

    return buffer;
}

/**
 * execute_command - Execute a command in the shell.
 *
 * @input: The input command.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *input)
{
    if (input == NULL)
        return -1;

    /* Remove the newline character at the end */
    input[strlen(input) - 1] = '\0';

    /* Use execvp to execute the command */
    if (execvp(input, (char *const []){input, NULL}) == -1)
    {
        perror("Error");
        return -1;
    }

    return 0;
}

/**
 * parse_input - Parse the input and execute the command.
 *
 * @input: The input command.
 * Return: 0 on success, -1 on failure.
 */
int parse_input(char *input __attribute__((unused)))
{
    /* Implementation of parsing and executing the input */
    return 0;
}

