#include "shell.h"
/**
 * shell_prompt - displays the shell prompt
 */
void shell_prompt(void)
{
	fflush(stdout);
	write(1, "($) ", 4);
}
