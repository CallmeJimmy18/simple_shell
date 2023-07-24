#include "shell.h"

/**
 * _strcmp - Compares string
 * @s1: string 1
 * @s2: Second string
 * Return: 0 on success
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * ncopy - Copies n number of charcters from src to dest
 * @dest: string to be replaced
 * @src: string to be copied
 * @n: number of bytes to copy
 * Return: 0 on sucess, 1 on faliure
 */
int ncopy(char *dest, char *src, int n)
{
	int i = 0;
	int len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	len++;
	if (n <= 0 || dest == NULL || src == NULL)
		return (1);
	if (n > len)
		n = len;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}
