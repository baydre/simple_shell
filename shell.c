#include "main.h"

/**
 * main - UNIX's entry point.
 * Return: zero (0) success.
 */
int main(void)
{
	char *command;
	char **tokens;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt_display();
		}
		command = cmd_read();

		if (tokens == NULL)
		{
			free(command);
			continue;
		}

		tokens = tokenize(command);
		if (access(tokens[0], X_OK) == -1)
		{
			write_error_message(tokens[0]);
		}
		else
		{
			execute_command(tokens);
		}
		free(command);
		free(tokens);
	}
	return (0);
}
