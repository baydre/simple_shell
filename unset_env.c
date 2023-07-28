#include "main.h"
/**
 * _unsetenv - short descrp
 * @name: the name of the env
 * Return: Returns 0.
 */
int _unsetenv(char *name)
{
	char **env = environ;
	int len, nlen;
	int environ_count = 0, i = 0, j;
	char **_arrNew;

	if (name == NULL)
		return (-1);
	while (*env != NULL)
	{
		environ_count++;
		env++;
	}
	_arrNew = malloc((environ_count + 1) * sizeof(char *));
	if (_arrNew == NULL)
		return (-1);
	env = environ;
	nlen = _strlen(name);
	while (*env != NULL)
	{
		if (_strncmp(name, *env, nlen) != 0 || (*env)[nlen] != '=')
		{
			len = _strlen(*env);
			_arrNew[i] = malloc((len + 1) * sizeof(char));
			if (_arrNew[i] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(_arrNew[j]);
				}
				free(_arrNew);
				return (-1);
			}
			_strcp(_arrNew[i], *env);
			i++;
		}
		env++;
	}
	_arrNew[i] = NULL;
	environ = _arrNew;
	return (0);
}
