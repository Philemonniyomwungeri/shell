#include "shell.h"

/**
 * print_pid - Print the process ID of the shell.
 */
void print_pid(void)
{
	pid_t pid;

	pid = getpid();
	printf("%u\n", pid);
}

