#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * get_arg_count - Gets argument count in the command
 * @s: Passed argumenet
 * @del: DElimer
 * Return: Number of arguments
 */

int get_arg_count(const char *s, const char *del)
{
	int count = 0;
	char *copy, *token;

	copy = strdup(s);
	if (copy == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, del);
	while (token)
	{
		token = strtok(NULL, del);
		count++;
	}

	free(copy);
	return (count);
}

/**
 * get_arg_vector - Gets argument vector
 * @s: Passed argument
 * @del: Delimiter
 * @ac: Argument count
 * Return: Token
 */

char **get_arg_vector(const char *s, const char *del, int ac)
{
	char **arg;
	char *copy, *token;
	int i = 0;

	copy = strdup(s);
	if (copy == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	arg = malloc(sizeof(char *) * ac);
	if (arg == NULL)
	{
		perror("Error: ");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, del);
        while (token)
	{
		arg[i] = strdup(token);
		if (arg[i] == NULL)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, del);
		i++;
	}

	free(copy);
	return (arg);
}
