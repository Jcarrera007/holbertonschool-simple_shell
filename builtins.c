#include "simpleshell.h"

int handle_builtin(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		builtin_exit(args);
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		builtin_env();
		return (1);
	}
	return (0);
}

void builtin_exit(char **args)
{
	free_args(args);
	exit(0);
}

void builtin_env(void)
{
	int i;
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}
