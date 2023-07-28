#include "main.h"

/**
 * _strncmp - compare n character of str1 and str2
 * @s1: string 1
 * @s2: string 2
 * @n: number of characters
 * Return: 0 on success
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
		return (-1);
		i++;
	}
	return (0);
}
