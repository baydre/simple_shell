#include "main.h"

/**
 * ato_i - custom atoi converts string to int
 * @s: string
 * Return: number if success, -1 if string contains non-numbers
 */
int ato_i(char *s)
{
	int x = 0;
	unsigned int num = 0;

	while (s[x] != '\0')
	{
		if (s[x] >= '0' && s[x] <= '9') /* calculate num */
			num = num * 10 + (s[x] - '0');
		if (s[x] > '9' || s[x] < '0') /* account for non-numbers */
			return (-1);
		x++;
	}
	return (num);
}
