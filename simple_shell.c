#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point for the program.
 *
 * Return: Always 0 on success.
 */
int main(void)
{
    char *const argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    if (execve("/bin/ls", argv, NULL) == -1)
    {
	    perror("execve");
	    return (EXIT_FAILURE);
    }
    /* This part will not be reached if execve is successful */
    printf("After execve\n");
    return (0);
}

