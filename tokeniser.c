#include "main.h"

/**
 * tokenise - tokenises the array of tokens
 * Return: the token count.
 */
char **tokenise(char *command)
{
	char **tokens = malloc(max_len_cmd * sizeof(char *));
	char *token = strtok(command, " \t\n");
	int count = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		tokens[count] = strdup(token);
		if (tokens[count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, " \t\n");
	}
	tokens[count] = NULL;
	return (tokens);
}
