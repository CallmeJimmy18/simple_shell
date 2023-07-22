#include "shell.h"

char *get_path(char *dir, char **env)
{
	char *buff = malloc(128);
	char **dirlist = NULL;
	char *tok = NULL;
	char *path = enpath(env);
	struct stat st;
	int j = 0;
	int i = 1;
	
	if (stat(dir, &st) == 0)
	{
		strcpy(buff, dir);
		free(path);
		return (buff);
	}
	dirlist = malloc(sizeof(char*) * 32);
	while (i < 31)
	{
		dirlist[i] = NULL;
		i++;
	}
	tok = strtok(path, ":");
	while (tok != NULL)
	{
		dirlist[j] = tok;
		tok = strtok(NULL, ":");
		j++;
	}
	j = 0;
	while (dirlist[j] != NULL)
	{
		strcpy(buff, dirlist[j]);
		strcat(buff, "/");
		strcat(buff, dir);
		if (stat(buff, &st) == 0)
		{
			free(dirlist);
			free(path);
			return (buff);
		}
		j++;
	}
	free(path);
	free(buff);
	free(dirlist);
	return(NULL);
}
