#include "main.h"

char* _getenv(const char* name)
{
	int i;
	size_t namelen = _strlen(name);
	
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], namelen) == 0 && environ[i][namelen] == '=')
		{
			return &environ[i][namelen + 1];
		}
	}
	return NULL;
}