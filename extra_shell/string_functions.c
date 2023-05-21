#include "shell.h"

/**
 * _strcpy - copies string to buffer
 * @dest: buffer
 * @src: string
 * Return: pointer to @dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _strlen - returns the lenth of a string
 * @s: the string
 * Return: length of string s
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; *s++;)
	{
		i++;
	}

	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: string to copy
 * Return: pointer to @dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - allocates space and assigns copy of a string
 * @str: string to duplicate
 * Return: NULL for error, pointer to string
 */

char *_strdup(char *str)
{
	char *new;
	unsigned int i;
	unsigned int j;

	if (str == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
		i++;
	i++;

	new = malloc(sizeof(char) * i);
	if (new == NULL)
		return (NULL);
	for (j = 0; j <= i; j++)
	{
		new[j] = str[j];
	}

	return (new);
}
