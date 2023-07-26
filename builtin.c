#include "main.h"

/**
 */
int isExit(char **tokens)
{
	/* "exit" built-in */
	if (strcmp(tokens[0], "exit") == 0)
	{
		return (1);
	}
	return (0);
}

int isEnv(char **tokens)
{
	/* "env" built-in */
	if (strcmp(tokens[0], "env") == 0)
	{
		char **env = environ;
		while(*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return (1);
	}
	return (0);
}
