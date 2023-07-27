#include "main.h"

/**
 * error_checker - entry point.
 * @argv: short desc.
 * @tokens: short desc. 
 * @fullpath: short desc.
 * @exit_status: short desc.
 * Return: zero.
 */

int error_checker(char **argv, char **tokens, char **fullpath, int *exit_status)
{
	char *path = _getenv("PATH");

	if (path == NULL || *path == '\0')
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": not found", 11);
		write(STDERR_FILENO, "\n", 1);
		*exit_status = 127;
		return (2);
	}

	if (access(tokens[0], X_OK) == -1)
	{
		*fullpath = witch(tokens[0], path);
		if (access(*fullpath, X_OK) == -1)
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
			write(STDERR_FILENO, ": not found", 11);
			write(STDERR_FILENO, "\n", 1);
			*exit_status = 127;
			return (2);
		}
	}

	return (0);
}
