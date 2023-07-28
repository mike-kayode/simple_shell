#include "shell.h"

/**
 * main - Function tht check if shell is called
 * Return: Success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		shell_work();
	}
	else
	{
		shell_no_work();
	}
	return (0);
}
