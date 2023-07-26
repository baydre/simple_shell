#include "main.h"

/**
 * prompt_display - displays a prompt on the STDOUT.
 */
void prompt_display(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}

/**
 * cmd_read - reads command from STDIN.
 * Return: it returns command.
 */
char *cmd_read(void)
{
	char *command = NULL;
	ssize_t read_byte;
	size_t count = 0;

	read_byte = getline(&command, &count, stdin);
	if (read_byte == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(EXIT_SUCCESS);
	}
	return (command);
}

/**
 * write_error_message - displays error message to the STDOUT.
 */
void write_error_message(const char *command)
{
	const char *error_message = ": command not found\n";

	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, error_message, strlen(error_message));
}
