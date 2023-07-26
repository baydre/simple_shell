/*
 * simple_shell, Task 3: v0.2 + handles "PATH" and
 * "fork" must not be called if command doesn't exist.
 */

#include "main.h"
/**
 * find_file - checks for file PATH.
 * @path: PATH
 * Return: zero 0.
 */
int find_file(char *path)
{
	struct stat buff;

	return ((stat(path, &buff) == 0));
}

/**
 * witch - checks for full PATH.
 * @filename: name of file
 * @path: PATH
 * Return: NULL
 */
char *witch(char *filename, char *path)
{
	char *path_cpy;
	char *tokens[1024];
	char *pathname;
	int i;

	if (path == NULL)
	{
		return (NULL);
	}
	path_cpy = strdup(path);

	/* Tokenize path */
	i = 0;

	tokens[i] = strtok(path_cpy, ":");

	while (tokens[i] != NULL)
	{
		pathname = malloc(strlen(tokens[i]) + strlen(filename) + 2);
		strcpy(pathname, tokens[i]);
		strcat(pathname, "/");
		strcat(pathname, filename);

	if (find_file(pathname))
	{
		free(path_cpy);
		return (pathname);
	}

		free(pathname);
		i++;
		tokens[i] = strtok(NULL, ":");
	}

	free(path_cpy);
	return (NULL);
}
