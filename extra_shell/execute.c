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

/**
 * exec_builtin - execute builtin functions
 * @av: array of arguments
 *
 * Return: 0 or function
 */
int exec_builtin(char **av)
{
	builtin builtins[] = {{"cd", _cd}, {"exit", _exit},
		{"env", _env}, {NULL, NULL}};
	int i = 0;

	while (builtins[i].s)
	{
		if (_strcmp(builtins[i].s, av[0]) == 0)
			return (builtins[i].f(av));
		i++;
	}

	return (0);
}

/**
 * create_fork - creates a fork and execute program with parameters
 * @av: array of program and parameters
 *
 * Return: return value of child process
 */
int create_fork(char **av)
{
	pid_t my_pid, child_pid;
	int waitstatus;

	child_pid = fork();
	if (child_pid == 0)
	{
		my_pid = execve(av[0], av, environ);
		if (my_pid == -1)
			exit(1);
	}
	else
		wait(&waitstatus);
	return (WEXITSTATUS(waitstatus));
}

/**
 * exec_line - execute line of commands
 * @line: user generated line of commands
 *
 * Return: void
 */
void exec_line(char *line)
{
	char **av, *p;
	char **lines;
	int i = 0;

	line[_strlen(line) - 1] = '\0';
	lines = tokenize(line, ';');
	free(line);
	while (lines[i])
	{
		av = tokenize(lines[i], ' ');
		i++;
		if (av != NULL)
		{
			if (!_strcmp(av[0], "exit"))
				free_more(line);
			if (!exec_builtin(av))
			{
				p = _strdup(av[0]);

				if (_path(a[0]) || _match(&av[0]))
					create_fork(av);
				else
					herror(av[0], "not found\n");
				free(p);
			}
			free_more(av);
		}
	}
	free_more(lines);
}
