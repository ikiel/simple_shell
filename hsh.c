#include "shell.h"

/**
 * main - the simple shell
 *
 * Return: 0
 */
int main(void)
{
	int i = 0, shell_mode = 1;
	char *token, *line = NULL;
	char *args[1024];
	size_t len = 0;
	int read;

	while (shell_mode)
	{
		fflush(stdout);
		shell_mode = isatty(STDIN_FILENO);
		if (shell_mode == 1)
			shell_prompt();
		read = getline(&line, &len, stdin);
		if (read == -1)
			return (-1);
		token = strtok(line, " ");
		while (token != NULL)
		{
			args[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		args[i] = NULL;

		for (i = 0; args[i] != NULL; i++)
			printf("%s\n", args[i]);
	}

	free(line);
	return (0);
}
