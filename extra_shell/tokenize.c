#include "shell.h"
/**
 * tokenize - splits a line into tokens
 * @line: line to split
 * @args: adress to save the tokens
 *
 * Return: void
 */
void tokenize(char *line, char *args[])
{
	char  *token;
	int i = 0;

	token = strtok(line, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
