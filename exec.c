#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>

extern char **environ;

/**
 *
 *@:
 *
 *Return:
*/

void exe(char *cmd, char *av[])
{
	char **envp = environ;
	int status;
	pid_t pid;

	if ((pid = fork()) == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(cmd, av, envp);
		perror("Exec");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
       	}

}
