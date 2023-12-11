#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024

/* Function prototypes */

/* main.c */
void interactive_mode(void);
void batch_mode(char *batch_file);

/* prompt.c */
int execute_command(char *input);
int parse_input(char *input);

/* utility.c */
char *read_line(void);
char **split_line(char *line);
void free_args(char **args);

#endif /* SHELL_H */

