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
 *exe - Executing the Command
 *@cmd: Command entered
 *@av: Pointer to argument vector
 *Return: Void
*/

void exe(char *cmd, char *av[])
{
        char **envp = environ;
        int status, execval;
        pid_t pid;

        if ((pid = fork()) == -1)
        {
                perror("fork");
		free(cmd);
                exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
		execval = execve(cmd, av, envp);
		if (execval == -1)
		{
			perror("Exec");
			free(cmd);
			exit(EXIT_FAILURE);
		}
        }
        else
        {
                wait(&status);
        }

}
