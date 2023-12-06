#include "shell.h"

/**
 * fork_and_execute - Fork a child process and execute a command.
 *
 * @command: The command to be executed.
 * Return: On success, the process ID of the child process.
 *         On failure, -1 is returned.
 */
pid_t fork_and_execute(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execute_command(command) == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}

	return (pid);
}

