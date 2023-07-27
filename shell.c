#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGHT 100
#define MAX_ARGS 10

/**
 * print_prompt - Function that open a program
 * Return: Succcess
 */

void print_prompt()
{
        printf("$) ");
}


/**
 * execute_command - Execution of second command
 * @command: character command
 * Return: Always sucess
 */

int execute_command(const char *command)
{
	char *token;
	char *args[MAX_ARGS + 2];
	pid_t pid;

	int arg_count = 0;

	token = strtok((char *)command, " ");
	while (token != NULL && arg_count < MAX_ARGS + 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (strcmp(args[0], "exit") == 0)
	{
		return (0);
	}

        pid = fork();

        if (pid < 0)
        {
                perror("Fork error");
                exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Command execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
	return (0);
}


/**
 * shell_main - Execution command
 * Return: Success
 */

void shell_main()
{
	char command[MAX_COMMAND_LENGHT];

	while (1)
	{
		print_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		if (execute_command(command) != 0)
		{
		}
	}
}
