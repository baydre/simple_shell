#include "main.h"

/**
 * command_execute - entry point.
 * @exit_status: short desc.
 * @fullpath: short desc.
 * @tokens: short desc.
 * Return: zero "0".
 */
int command_execute(int *exit_status, char *fullpath, char *tokens[])
{
	pid_t c_pro;
	int status;

	c_pro = fork();
	if (c_pro == -1)
	{
		perror("fork");
		return (1);
	}
	if (c_pro == 0)
	{
		execve(fullpath, tokens, environ);
		*exit_status = 2;
		perror("execve");
		exit(*exit_status);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			*exit_status = WEXITSTATUS(status);
		}
	}
	if (fullpath != tokens[0])
		free(fullpath);
	return (0);
}
