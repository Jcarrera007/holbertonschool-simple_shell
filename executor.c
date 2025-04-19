#include "simpleshell.h"

int execute_command(char **args)
{
	pid_t pid;

	if (handle_builtin(args))
		return (1);

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
