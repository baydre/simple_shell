#include "main.h"

/**
 * main - entry point.
 * @argc: number of argument count
 * @argv: argument vector
 * Return: zero.
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line = NULL;
	size_t length = 0;
	char *tokens[1024];
	int count, output;
	char *fullpath;
	int exit_status = 0;

	while (1)
	{
		output = prompt_handler(&length, &line);
		if (output == 1)
			break;
		count = 0;
		tokens[count] = strtok(line, " \t\n");
		while (tokens[count] != NULL)
		{
			count++;
			tokens[count] = strtok(NULL, " \t\n");
		}
		tokens[count] = NULL;
		fullpath = tokens[0];
		output = builtin_checker(count, tokens, &exit_status);
		if (output == 1)
			break;
		else if (output == 2)
			continue;
		output = error_checker(argv, tokens, &fullpath, &exit_status);
		if (output == 1)
			break;
		else if (output == 2)
			continue;
		output = command_execute(&exit_status, fullpath, tokens);
		if (output == 1)
			break;
		else if (output == 2)
			continue;
	}
	free(line);
	return (exit_status);
}
