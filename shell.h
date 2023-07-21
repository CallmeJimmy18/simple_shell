#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void tokeniz(char *cmd, char **args);
int _strcmp(char *s1, char *s2);
int str_cmp(char *s1, char *s2);
char *enpath(char **list);
int copy(char *dest, char*src);
int add(char *dest, char*src);
char *get_path(char *dir, char **env);
void print_env(char ** env);
void prints(char *s);
#endif
