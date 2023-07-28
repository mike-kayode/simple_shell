#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGHT 1024

/**
 * main - Function that open a program
 * Return: Succcess
 */

int main(void)
{
	pid_t pid;
	char command[MAX_COMMAND_LENGHT];

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(command, MAX_COMMAND_LENGHT, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			extern char **environ;
			char **argv = (char **)malloc(2 * sizeof(char *));
			
			if (argv == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			argv[0] = command;
			argv[1] = NULL;

			if (execve(command, argv, environ) == -1)
			{
				perror(command);
			}

			free(argv);
                        exit(EXIT_FAILURE);
                }
		else
		{
			int status;

			if (wait(&status) == -1)
			{
				perror("wait");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}

