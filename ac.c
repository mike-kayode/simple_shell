#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"
#include <errno.h>
#include <string.h>

/**
 *_ac - Gets argument count in the command
 *@s: Passed argument
 *@del: Delimiter
 *
 *Return: Number of arguments
*/

int _ac(char **arg, char *del)
{
	char *token;
	int count = 0;

	token = strtok(*arg, del);
	if (token == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		token = strtok(NULL, del);
		count++;
	}
	return (count);
}

/**
 *_acv - Gets argument vector
 *@s: Passed argument
 *@del: Delimiter
 *@ac: Argument count
 *
 *Return: Tokens
*/

char *_acv(char **arg, char *del, int ac)
{
	int i = 0;
	char *token;

	arg = malloc(sizeof(char *) * ac);
	token = strtok(*arg, del);
	if (token == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		arg[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	return (token);
}
