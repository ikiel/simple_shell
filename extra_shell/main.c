#include "shell.h"

/**
 * main - the simple shell
 *
 * Return: 0
 */
int main(void)
{
	shell_loop(isatty(STDIN_FILENO));

	return (0);
}

/**
 * shell_loop - Shell loop
 * @input: isatty(STDIN_FILENO)
 *
 * Return: void
 */
void shell_loop(int input)
{
	char *line = NULL;
	ssize_t a = 0;
	size_t len = 0;

	while (1)
	{
		if (input)
			prompt();
		a = getline(&line, &len, stdin);
		if (a == EOF)
		{
			free(line);
			exit(0);
		}
		if (_strcmp(line, "\n"))
		{
			execute(line);
			line = NULL;
		}
	}
}
