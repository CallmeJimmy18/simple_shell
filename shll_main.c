#include "shell.h"
#define EXITED {\
	printf("exit\n");\
	break;\
	}
#define ENV {\
	print_env(env);\
	free(args);\
	continue;\
	}
#define PATH {\
	free(args);\
	}
#define ERROR {\
	prints(argv[0]);\
	prints(": No file or directory\n");\
	}
/**
 * main - Runs shell
 * @argc: argument count
 * @argv: arguments
 * @env: environment
 * Return: 0 on success, 1 on fail
 */
int main(int argc, char **argv, char **env)
{
	char *cmd = NULL, *path = NULL;
	ssize_t cmdlin;
	size_t b = 0;
	char **args = NULL;
	pid_t pid;

	while (1)
	{
		prints("//Gar-Lia:==> ");
		cmdlin = getline(&cmd, &b, stdin);
		if (cmdlin == 1)
			continue;
		args = malloc(sizeof(char *) * 32);
		tokeniz(cmd, args);
		if (_strcmp(args[0], "exit") == 0)
			EXITED;
		if (_strcmp(args[0], "env") == 0)
			ENV;
		path = get_path(args[0], env);
		if (path == NULL)
		{
			ERROR;
			freed(args, path);
			continue;
		}
		else
			args[0] = path;
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
				PATH;
		}
		else
			wait(NULL);
		freed(args, path);
	}
	freed(args, cmd);
	return (0);
}
