#include "main.h"

/**
 * add - Concatenates 2 strings
 * @dest: Concatenated string;
 * @src: pointer to substring to be added
 * Return: 0 on sucess, 1 on faliure
 */
int add(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	if (dest == NULL || src == NULL)
		return (1);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';

	return (0);
}

/**
 * copy - Copies string from src to dest
 * @dest: string to be replaced
 * @src: string to be copied
 * Return: 0 on sucess, 1 on faliure
 */
int copy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL)
		return (1);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (0);
}

/**
 * str_cmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are the same ;1 if strings are different
 */
int str_cmp(char *s1, char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
	{
		return (1);
	}
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * prints - prints string to terminal
 * @s: string to be printed
 */
void prints(char *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			i++;
		}
		write(STDOUT_FILENO, s, i);
	}
}

/**
 * enpath - get the path enviromental variable
 * @list: array of enviromental variables
 * Return: pointer to path
 */
char *enpath(char **list)
{
	char *item;
	char *value;
	int j = 0;

	if (list == NULL)
		return (NULL);
	while (list[j] != NULL)
	{
		item = strtok(list[j], "=");
		if (str_cmp(item, "PATH") == 0)
		{
			value = strtok(NULL, "=");
			return (value);
		}
		j++;
	}
	return (NULL);
}

