#include "shell.h"

/**
 * execcmd - executes a command in shell
 * @argv: the list of commands parsed to shell
 *
 * Return: void
 */
void execcmd(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t child_pid;

	if (argv == NULL)
		return;
	command = argv[0];

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
			real_command = pathfinder(command);
		if (execve(real_command, argv, NULL) == -1)
			perror("execve");
	}
	else if (child_pid < 0)
		perror("fork");
	else
		wait(NULL);
}

/**
 * pathfinder - find a command's file path
 * @command: the command whose file path is being searched
 *
 * Return: file path | NULL for failure
 */
char *pathfinder(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len = _strlen(command), dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		dir_len = _strlen(path_token);
		file_path = malloc(command_len + dir_len + 2);
		if (file_path == NULL)
			return (NULL);
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		_strcat(file_path, "\0");

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	if (stat(command, &buffer) == 0)
		return (command);

	return (NULL);
}
