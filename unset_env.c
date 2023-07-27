#include "main.h"

int _unsetenv(char *name)
{
	char **env = environ;
	int len, nameLen;
	int environ_cnt = 0, i = 0, j;
	char **new_arr;

	if (name == NULL)
		return (-1);
	while (*env != NULL)
	{
		environ_cnt++;
		env++;
	}
	new_arr = malloc((environ_cnt + 1) * sizeof(char *));
	if (new_arr == NULL)
		return (-1);
	env = environ;
	nameLen = _strlen(name);
	while (*env != NULL)
	{
		if (_strncmp(name, *env, nameLen) != 0 || (*env)[nameLen] != '=')
		{
			len = _strlen(*env);
			new_arr[i] = malloc((len + 1) * sizeof(char));
			if (new_arr[i] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(new_arr[j]);
				}
				free(new_arr);
				return (-1);
			}
			_strcp(new_arr[i], *env);
			i++;
		}
		env++;
	}
	new_arr[i] = NULL;
	environ = new_arr;
	return (0);
}
