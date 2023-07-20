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

/**
 *wr - Writes the prompt
 *
 *
 *Return:void
*/

void wr(void)
{
	char wd[1024];
	
	getcwd(wd, sizeof(wd));
	write(STDOUT_FILENO, wd, _strlen(wd));
	write(STDOUT_FILENO, "$ ", 2);
}
