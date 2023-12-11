// utility.c

#include <stdio.h>
#include <stdlib.h>

/**
 * read_line - Read a line from the standard input.
 *
 * Return: A pointer to the allocated string containing the input line.
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        free(line);
        return NULL;
    }

    return line;
}

