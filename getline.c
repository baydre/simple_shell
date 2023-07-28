#include "main.h"

/**
 * _getline - short desc. 
 * @str: buffer
 * Return: number of characters read
 */
size_t _getline(char **str)
{
	ssize_t x = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	while (t2 == 0 && (x = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (x == -1) 
			return (-1);

		buff[x] = '\0'; 

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			x++;
			*str = malloc(sizeof(char) * x);
			*str = _strcp(*str, buff);
			size = x;
			t = 1;
		}
		else
		{
			size += x;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
