#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char *environ;

void shell_loop(int input);
void prompt();
void execcmd(char **argv);
char *pathfinder(char *command);
char **tokenize(char *line, const char *delim);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string functions */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char c);
char *_strdup(char *str);

/* free */
void free_more(char **argv);

/* execute.c */
int exec_builtin(char **av);
int create_fork(char **av);
void exec_line(char *line);

#endif /* MAIN_H */
