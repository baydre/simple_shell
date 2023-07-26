#include "main.h"

/**
 * execute_command - creates and executes a child process
 * using 'fork' and 'execve'.
 * @args: arguments to be executed.
 */
void execute_command(char *command, char **args)
{
	pid_t c_pro;
	int status;

	c_pro = fork();
	if (c_pro == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (c_pro == 0)
	{
		execve(command, args, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(c_pro, &status, 0);
	}
}
