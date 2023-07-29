#include "main.h"

/**
* _setenv - short desc.
* @bay: The name of the environment variable
* @value: The value to be assigned to the environment variable
* @present: Pointer to the list_paths structure
* This function sets the value of an environment variable.
*/

void _setenv(char *bay, char *value, path_list *present)
{
	int count = 0;
	char *_env = NULL;

	if (bay == NULL || value == NULL)
	{
		return;
	}
	if (present == NULL)
	{
		return;
	}
	count = _strlen(bay) + _strlen(value) + 2;
	_env = malloc(count);
	if (_env == NULL)
	{
		return;
	}
	_strcp(_env, bay);
	_strcat(_env, "=");
	_strcat(_env, value);
	_env[count - 1] = '\0';
	free(_env);

}
