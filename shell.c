#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGHT 100
#define MAX_ARGS 10

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
			char *token;
			char *argv[MAX_COMMAND_LENGHT / 2 + 1];
			int i = 0;

			token = strtok(command, " ");
			while (token != NULL)
			{
				argv[i++] = token;
				token = strtok(NULL, " ");
			}
			argv[i] = NULL;

			if (execvp(argv[0], argv) == -1)
                {
                        perror("execvp");
		}
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

