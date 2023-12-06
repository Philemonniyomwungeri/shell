#include "shell.h"

/**
 * print_ppid - Print the parent process ID of the shell.
 */
void print_ppid(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
}

