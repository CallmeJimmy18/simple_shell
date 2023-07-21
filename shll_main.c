#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *cmd = NULL, *path = NULL;
	ssize_t cmdlin;
	size_t b = 0;
	char **args = NULL;
	pid_t pid;

	while (1)
	{
		printf("//Gar-Lia:==> ");
		cmdlin = getline(&cmd, &b, stdin);
		if (cmdlin == 1)
		{
			free(cmd);
			continue;
		}
        	args = malloc(sizeof(char *) * 32);
		tokeniz(cmd, args);
		/*int k = 0;
		while (args[k] != NULL)
		{
			printf("++++%s+++++", args[k]);
			k++;
		}*/
		if (_strcmp(args[0], "exit") == 0)
		 {
                        printf("exit\n");
			break;
                }
		if (_strcmp(args[0], "env") == 0)
		{
			print_env(env);
			continue;
		}
		path = get_path(args[0], env);
		if (path == NULL)
		 {
			 printf("%s: No such file or directory (path)\n", argv[0]);
			 free(args);
			 free(path);
			 continue;
		 }
		 else
			args[0] = path;
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				printf("%s: No such file or directory (execve)\n", argv[0]);
				free(args);
				return 1;
			}
		} 
		else if (pid == -1)
			perror("error");

		 else 
			wait(NULL);
	    	 free(args);
		 free(path);
	}
	free(args);
	free(cmd);
	return (0);
}
