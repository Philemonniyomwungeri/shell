#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *prompt_user(void);
int execute_command(char *input);
int parse_input(char *input);

#endif /* SHELL_H */

