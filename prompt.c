#include "main.h"

/**
 * prompt_handler - handles prompt.
 * @len: short desc.
 * @line: short desc.
 * Return: zero.
 */
int prompt_handler(size_t *len, char **line)
{
	ssize_t read_bytes;
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read_bytes = getline(line, len, stdin);
	if (read_bytes == -1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	return (1);
	}
	return (0);
}
