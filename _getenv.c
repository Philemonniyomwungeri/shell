#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: If the environment variable is found, returns a pointer to its value;
 * otherwise, returns NULL.
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
	}

	return (NULL);
}

/**
 * main - Example usage of the _getenv function.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *path_value = _getenv("PATH");

	if (path_value != NULL)
	{
		printf("PATH = %s\n", path_value);
	}
	else
	{
		printf("PATH not found in environment\n");
	}

	return (0);
}

