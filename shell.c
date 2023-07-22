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
	char *cmd = NULL;
	char *cmd_cp = NULL;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			wr();
			ac = 0;
			av = NULL;
			if (getline(&cmd, &n, stdin) == -1)
			{
				write(STDOUT_FILENO, "Exiting the shell\n", 18);
				free(cmd);
				break;
			}
			cmd_cp = _strdup(cmd);
			ac = get_arg_count(cmd, " \n");
			av = malloc(sizeof(char *) * ac);
			if (av == NULL)
			{
				perror("Malloc");
				free(av);
				exit(EXIT_FAILURE);
			}
			av = get_arg_vector(cmd_cp, " \n", ac);
			exe(av[0], av);
			free(av);
			free(cmd_cp);
		}
	}
	return (0);
}
