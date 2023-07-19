#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int str_cmp(char *s1, char*s2);
char *enpath(char **list);
int copy(char *dest, char*src);
int add(char *dest, char*src);
char *get_path(char *dir, char**env);
void print_env(char ** env);
void prints(char *s);
#endif
