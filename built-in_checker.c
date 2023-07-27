#include "main.h"

/**
 * builtin_checker - entry point.
 * @count: short desc.
 * @tokens: short desc.
 * @exit_status: short desc.
 * Return: zero.
 */

int builtin_checker(int count, char **tokens, int *exit_status)
{
	char **env = environ;

	if (count < 1)
		return (2);

	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			*exit_status = ato_i(tokens[1]);
		}
		return (1);
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
		return (2);
	}
	if (_strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(tokens[1]);
		return (2);
	}
	return (0);
}
