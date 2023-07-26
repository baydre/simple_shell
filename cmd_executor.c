#include "main.h"

/**
 * execute_command - creates and executes a child process
 * using 'fork' and 'execve'.
 * @args: arguments to be executed.
 */
void execute_command(char **args)
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
		execvp(args[0], args);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(c_pro, &status, 0);
	}
}
