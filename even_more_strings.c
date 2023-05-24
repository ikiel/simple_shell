#include "shell.h"

/**
 * _strcmp_n - compares n bytes of two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to comp
 *
 * Return: difference in comparison
 */

int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, res = *s1 - *s2;

	while (i <= n)
	{
		res = *(s1++) - *(s2++);
		if (res != 0)
			break;
		i++;
	}

	return (res);
}

/**
 * _strdup - copy a string to a new allocated block of memory
 * @str: string
 *
 * Return: pointer to duplicated string, NULL if insufficient memory
 */

char *_strdup(char *str)
{
	int len = 0; /* index of terminating null byte */
	char *ptr = NULL;

	if (!str)
		return (NULL);
	while (*str)
	{
		len++;
		str++;
	}
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		while (len >= 0)
			*(ptr + len--) = *(str--);
	}
	return (ptr);
}

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated strings
 */

char *str_concat(char *s1, char *s2)
{
	char *ptr;
	int i = 0;
	int j = 0;
	int x = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j] != '\0')
	{
		j++;
	}
	ptr = malloc((i * sizeof(char)) + (j * sizeof(char)) + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i] != '\0'; i++)
	{
		ptr[i] = s1[i];
		x++;
	}
	for (j = 0; s2[j] != '\0'; j++)
	{
		ptr[x] = s2[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

/**
 * _strchr - locates a character in a string
 * @s: where to start looking
 * @c: values to find
 *
 * Return: pointer to begining of mem area
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (0);
}

