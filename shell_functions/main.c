#include "main.h"

int main(int argc, char **argv, char **env)
{
	print_env(env);
	prints("Hello\n");
	/*char *buff = NULL;

	buff = get_path(argv[1], env);
	if (buff == NULL)
	{
		printf("Command does not exist\n");
		return (1);
	}
	printf("Comand is at = %s\n", buff);
	free(buff);*/
	return (0);
}
