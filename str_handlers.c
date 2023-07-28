#include "main.h"

/**
 * _strlen - short description
 * @str: string
 * Return: return len.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcat - concatenate strings
 * @dest: where the string is to be appended.
 * @src: string to append.
 * Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: duplicated string pointer in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
	len++;
	len++;

	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
	return (NULL);

	i = 0;
	while (i < len)
	{
	*(duplicate_str + i) = *(str + i);
	i++;
	}

	return (duplicate_str);
}

/**
 * _strcp - copies string pointed to by src
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of string
 */

char *_strcp(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)


	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcmp - compares strings
 * @s1: first string
 * @s2: second string
 * Return: int values, otherwise 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
	i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}
