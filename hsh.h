#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

extern char **environ;

int execute_command(char **args);
char **parse_input(char *input);
int _strlen(char *s);
void free_array(char **array);
void print_error(char *program, char *message, int status);

#endif /* HSH_H */

