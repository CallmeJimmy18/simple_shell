#include "main.h"

char *get_path(char *dir, char**env)
{
	char *buff = malloc(128);
	char *path = enpath(env);
	char **dirlist = NULL;
	char *tok = NULL;
	struct stat st;
	int j = 0;
	int i = 1;
	
	if (stat(dir, &st) == 0)
	{
		copy(buff, dir);
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
		copy(buff, dirlist[j]);
		add(buff, "/");
		add(buff, dir);
		if (stat(buff, &st) == 0)
		{
			free(dirlist);
			return (buff);
		}
		j++;
	}
	free(buff);
	free(dirlist);
	return(NULL);
}
