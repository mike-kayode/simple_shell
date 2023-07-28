#include "shell.h"

/**
 * read_line - Function that read a line
 * Return: Pointer thst point to line content
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
