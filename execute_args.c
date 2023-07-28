#include "shell.h"

/**
 * execute_args - Discover if it is inbuilt command
 * @args: argument command
 * Return: 1 o success
 */

int execute_args(char **args)
{
	char *inbuilt_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*inbuilt_func[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	long unsigned int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (; i < sizeof(inbuilt_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], inbuilt_func_list[i]) == 0)
		{
			return ((*inbuilt_func[i])(args));
		}
	}
	return (new_process(args));
}
