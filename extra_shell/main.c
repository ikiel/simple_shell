#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *token;
	char **arguments = NULL;
	char *line = NULL, *line_cpy = NULL;
	size_t len = 0;
	ssize_t nread;
	const char *delim = " \n";
	int i = 0; ntokens = 0;

	while(1)
	{
		printf("($) ", prompt);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			return (-1);
		}
		line_cpy = malloc(sizeof(char) * nread);
		if (line_cpy == NULL)
			return (-1);
		strcpy(line_cpy, line);

		token = strtok(line, delim);
		while (token != NULL)
		{
			ntokens++;
			token = strtok(NULL, delim);
		}
		ntokens++;

		arguments = malloc(sizeof(char *) * ntokens);
		token = strtok(line_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			arguments[i] = malloc(sizeof(char) * strlen(token));
			strcpy(arguments[i], token);
			token = strtok(NULL, delim);
		}
		arguments[i] = NULL;

		free(arguments);
		free(line_cpy);
		free(line);
	}

	return (0);
