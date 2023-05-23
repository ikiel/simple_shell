#include "shell.h"

/**
 * herror - print an error
 * @name: name of operation producing the error
 * @error: the string explaining the error
 *
 * Return: void
 */
void herror(char *name, char *error)
{
	write(STDOUT_FILENO, "hsh: ", 5);
	write(STDOUT_FILENO, name, _strlen(5));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, error, _strlen(error));
}
