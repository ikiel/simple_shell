#include "shell.h"
/**
 * read_line - get input from user
 * @line: the save destination
 * @len: length of line
 * Return: number of characters read | -1 on failure
 */
ssize_t read_line(char *line, size_t len)
{
	int i = 0, read;

	read = getline(&line, &len, stdin);
	if (read == -1)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			line[i] = 0;
		i++;
	}

	return (read);
}
