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

void prompt(void);
void execcmd(char **argv);
char *pathfinder(char *command);

/* string functions */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _putchar(char c);
char *_strdup(char *str);

/* free */
void free_more(char **argv);

#endif /* MAIN_H */
