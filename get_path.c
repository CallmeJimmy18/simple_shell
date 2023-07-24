#include "shell.h"
/**
 * get_path - Returns full path
 * @dir: command name
 * @env: environment
 * Return: buff on success, Null if fail
 */
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
		copy(buff, dir);
		free(path);
		return (buff);
	}
	dirlist = malloc(sizeof(char *) * 32);
	while (i < 31)
	{
		dirlist[i] = NULL;
		i++;
	}
	token_p(path, dirlist);
	while (dirlist[j] != NULL)
	{
		copy(buff, dirlist[j]);
		add(buff, "/");
		add(buff, dir);
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
	return (NULL);
}
