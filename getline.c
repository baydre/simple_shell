#include "main.h"

/**
 * _getline - stores into malloced buffer the user's command into shell
 * @str: buffer
 * Return: number of characters read
 */
size_t _getline(char **str)
{
	ssize_t x = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* read while there's stdin greater than buffsize; -1 to add a '\0' */
	while (t2 == 0 && (x = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (x == -1) /* check if read errored */
			return (-1);

		buff[x] = '\0'; /* terminate buff with \0 to use with _strcat */

		n = 0; /* last loop if \n is found in the stdin read */
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		/* copy what's read to buff into get_line's buffer */
		if (t == 0) /* malloc the first time */
		{
			x++;
			*str = malloc(sizeof(char) * x);
			*str = _strcp(*str, buff);
			size = x;
			t = 1;
		}
		else /* _realloc via _strcat with each loop */
		{
			size += x;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
