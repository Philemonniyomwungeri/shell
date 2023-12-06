#include "shell.h"

/**
 * wait_handler - Wait for a child process to complete and handle its status.
 *
 * @pid: The process ID of the child.
 * Return: The exit status of the child process.
 */
int wait_handler(pid_t pid)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Waitpid");
		return (-1);
	}

	return (status);
}

/**
 * main - Entry point for the wait program.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;

	/* Replace this section with the actual code that creates a child process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork");
		return (-1);
	}
	else if (child_pid == 0)
	{
		/* Code to execute in the child process */
		/* For example: execve("/bin/ls", ["ls", "-l", NULL], environ); */
		exit(EXIT_SUCCESS);
	}

	status = wait_handler(child_pid);
	if (status == -1)
		return (-1);

	/* Add any additional handling of the status if needed */

	return (0);
}

