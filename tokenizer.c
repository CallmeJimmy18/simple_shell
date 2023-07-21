#include "shell.h"

/*
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
