#include <stdio.h>
#include "shell.h"

/**
 * shell_work - UNIX Command line interpreter
 * Return: Void
 */

void shell_work(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		printf("prompt$ ");
		line = read_line();
		args = split_line(line);
		status = execute_args(args);

		free(line);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	}
	while (status == -1);
}
