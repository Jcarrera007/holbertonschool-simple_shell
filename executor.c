#include "simpleshell.h"

/**
 * execute_external - forks and executes a non-builtin command
 * @args: NULL-terminated array of arguments
 *
 * Return: 1 to continue shell loop
 */
static int execute_external(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "Tu mismo: '%s'? Misterio.\n", args[0]);
			perror("Tremendo Mosquero");
		}
		_exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}

/**
 * execute - resolves and runs a command (builtin or external)
 * @args: NULL-terminated array of arguments
 *
 * Return: 1 to continue shell loop, 0 to exit
 */
 int execute(char **args)
 {
	 if (args[0] == NULL)
		 return (1);
 
	 if (strcmp(args[0], "cd") == 0)
		 return (builtin_cd(args));
	 if (strcmp(args[0], "exit") == 0)
		 return (builtin_exit(args));
	 if (strcmp(args[0], "pid") == 0)
		 return (builtin_pid(args));
	 /* note: no check for ls, cat, pwd, joke—fall through to execvp */
 
	 return (execute_external(args));
 }
