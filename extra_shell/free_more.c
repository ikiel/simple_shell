#include "shell.h"

/**
 * free_more - frees double malloc'ed memories
 * @argv: addresses to free
 */

void free_more(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
