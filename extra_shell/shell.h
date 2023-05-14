#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void shell_prompt();
ssize_t read_line(char *line, size_t len);
void tokenize(char *line, char *args[]);

#endif /* MAIN_H */
