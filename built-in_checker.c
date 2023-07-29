#include "main.h"

/**
 * builtin_checker - entry point.
 * @count: short desc.
 * @tokens: short desc.
 * @argv: short desc.
 * @exit_status: short desc.
 * Return: zero.
 */

int builtin_checker(int count, char **tokens, char **argv, int *exit_status)
{
	char **env = environ;

	if (count < 1)
		return (2);

	if (_strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			if (atoi(tokens[1]))
				if (atoi(tokens[1]) >= 0)
			*exit_status = ato_i(tokens[1]);
				else
					illegal_number(tokens, argv, exit_status);
			else
			{
				illegal_number(tokens, argv, exit_status);
			}
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
