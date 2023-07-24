#include "shell.h"

/**
 * tokeniz - This will tokenize the strng
 * @cmd: this is the command
 * @args: this is the argument
 */
void tokeniz(char *cmd, char **args)
{
	char *token;
	int i = 0;
	char *dlm = " \n";

	token = strtok(cmd, dlm);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, dlm);
		i++;
	}
	args[i] = NULL;
}

/**
 * token_p - tokenize string
 * @path: this is the path
 * @dirlist: list of paths
 */
void token_p(char *path, char **dirlist)
{
	char *tok;
	int j = 0;

	tok = strtok(path, ":");
	while (tok != NULL)
	{
		dirlist[j] = tok;
		tok = strtok(NULL, ":");
		j++;
	}
}

/**
 * freed - frees argument lis and char pointer
 * @args: This is the double pointer
 * @ptr: single pointer
 */
void freed(char **args, char *ptr)
{
	free(args);
	free(ptr);
}
