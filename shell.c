#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/**
 *main - Entry to the program
 *@ac: Argument count
 *@av: NULL terminated argument vector
 *Return: Zero on success
*/

int main(int ac, char **av)
{
	char *cmd = NULL, *delim = " \0";
	char *cmd_cp = NULL;
	size_t n = 0;
	int nc;

	while (1)
	{
		ac = 0;
		av = NULL;
		if (isatty(STDIN_FILENO) == 1)
			wr();
		nc = getline(&cmd, &n, stdin);
		if (nc == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			free(cmd);
			break;
		}
		cmd_cp = _strdup(cmd);
		ac = get_arg_count(cmd, delim);
		av = malloc(sizeof(char *) * ac);
		if (av == NULL)
		{
			perror("Malloc");
			free(cmd_cp);
			exit(EXIT_FAILURE);
		}
		av = get_arg_vector(cmd_cp, " \n", ac);
		exe(av[0], av);
	}
	return (0);
}
