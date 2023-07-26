#include "shell.h"
char *cmd = NULL;
#define EXITED {\
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
#define IERROR {\
	prints(argv[0]);\
	prints(": 1: ");\
	prints(args[0]);\
	prints(": not found\n");\
	}
#define ERROR {\
	prints(argv[0]);\
	prints(": No such file or directory\n");\
	}
#define FEXIT {\
	free(cmd);\
	exit(0);\
	}
/**
 * sig_hand - handles signal of SIGINT
 * @num: unused variables
 */
void sig_hand(int num __attribute__((unused)))
{
	free(cmd);
	prints("\n");
	exit(0);
}
/**
 * main - Runs shell
 * @argc: argument count
 * @argv: arguments
 * @env: environment
 * Return: 0 on success, 1 on fail
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *path = NULL;
	ssize_t cmdlin = 0;
	size_t b = 0;
	int inter = isatty(STDIN_FILENO);
	char **args = NULL;
	pid_t pid;

	signal(SIGINT, sig_hand);
	while (1)
	{
		if (inter == 1)
			prints("//Gar-Lia:==> ");
		cmdlin = getline(&cmd, &b, stdin);
		if (cmdlin == 1)
			continue;
		else if (cmdlin == -1)
		{
			if (inter == 1)
				printf("\n");
			FEXIT;
		}
		args = malloc(sizeof(char *) * 32);
		tokeniz(cmd, args);
		if (_strcmp(args[0], "exit") == 0 || args[0][0] == 4)
			EXITED;
		if (_strcmp(args[0], "env") == 0)
			ENV;
		path = get_path(args[0], env);
		if (path == NULL)
		{
			if (inter != 1)
				IERROR;
			if (inter == 1)
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
