#include "shell.h"

/**
 * print_stat - Print the status of the last command.
 *
 * @status: The exit status of the last command.
 */
void print_stat(int status)
{
	if (WIFEXITED(status))
		printf("Exit status: %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("Terminated by signal %d\n", WTERMSIG(status));
}

/**
 * stat_handler - Handle the status of the last command.
 *
 * @status: The exit status of the last command.
 */
void stat_handler(int status)
{
	if (status == -1)
	{
		perror("Error");
		return;
	}

	print_stat(status);
}

/**
 * main - Entry point for the stat program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int status = 0; /* Replace this with the actual exit status */

	stat_handler(status);

	return (0);
}

