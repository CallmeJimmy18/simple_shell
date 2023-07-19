#include "main.h"

/**
 * print_env - prints array of enviromental variables
 * @env: array of enviromental variables
 */
void print_env(char **env)
{
	int i = 0;

	if (env != NULL)
	{
		while (env[i] != NULL)
		{
			prints(env[i]);
			prints("\n");
			i++;
		}
	}
}
