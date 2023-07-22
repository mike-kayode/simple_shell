#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/**
 *
 *@:
 *
 *Return:
*/

int main(int ac, char **av)
{
	char *cmd = NULL;
	char *tok = NULL;
	size_t n = 0;
	int i = 0;

	ac = 0;
	av = NULL;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			wr();
			if (getline(&cmd, &n, stdin) == -1)
			{
				write(STDOUT_FILENO, "Exiting the shell\n", 18);
				break;
			}
			av = malloc(sizeof(char *) * ac);
			if (av == NULL)
			{
				perror("Malloc");
				exit(EXIT_FAILURE);
			}
			tok = strtok(cmd, " \n");
			while(tok)
			{
				av[i] = tok;
				tok = strtok(NULL, " \n");
				i++;
			}
			av[i] = NULL;
			if (ac == 1)
			{
				exe(av[0], av);
			}
			else
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			free(av);
			free(cmd);
		}
	}
	else
	{

	}

	return (0);
}
