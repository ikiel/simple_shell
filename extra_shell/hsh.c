#include "shell.h"

/**
 * main - the simple shell
 *
 * Return: 0
 */
int main(void)
{
	int i = 0, num_tokens = 0;
	char *line = NULL, *token, *line_copy, **args = NULL;
	size_t len;
	ssize_t read;

	while (1)
	{
		prompt();
		read = getline(&line, &len, stdin);
		if (read == -1)
			return (-1);
		line_copy = malloc(sizeof(char) * read);
		if (line_copy == NULL)
			return (-1);
		_strcpy(line_copy, line);
		token = strtok(line, " \n");
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, " \n");
		}
		num_tokens++;
		args = malloc(sizeof(char *) * num_tokens);
		if (args == NULL)
			return (-1);
		token = strtok(line_copy, " \n");
		for (i = 0; token != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(args[i], token);
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;
		execcmd(args);
	}

	free(line);
	free_more(args);
	free(line_copy);
	return (0);
}
