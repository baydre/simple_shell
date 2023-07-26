#include "main.h"

/**
 * main - UNIX's entry point.
 * Return: zero (0) success.
 */
int main(void)
{
	char *command, *str_path, *fetch_get = getenv("PATH");
	char **tokens;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_display();
		
		command = cmd_read();

		tokens = tokenise(command);
		if (tokens == NULL)
		{
                        free(command);
                        continue;
		}
		if (isExit(tokens))
                        break;
                if (isEnv(tokens))
                        continue;
		if (access(tokens[0], X_OK) == -1)
		{
			str_path = witch(tokens[0], fetch_get);
			if (str_path != NULL)
				execute_command(str_path, tokens);
			else
				write_error_message(tokens[0]);
		}
		else
		{
			execute_command(tokens[0], tokens);
		}
		free(command);
		free(tokens);
	}
	return (0);
}
