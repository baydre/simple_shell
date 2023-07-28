#include "main.h"
/**
 * _getenv - short desc.
 * @name: environment name.
 * Return: NULL.
 */
char *_getenv(const char *name)
{
	int i;
	size_t nlen = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], nlen) == 0 && environ[i][nlen] == '=')
		{
			return (&environ[i][nlen + 1]);
		}
	}
	return (NULL);
}
