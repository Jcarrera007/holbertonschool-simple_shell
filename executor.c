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
    int   wstatus;

    pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
        print_error(g_prog_name, args[0], g_line_count);
        _exit(127);
    }
    else if (pid < 0)
    {
        perror(g_prog_name);
        g_last_status = 1;
    }
    else
    {
        waitpid(pid, &wstatus, 0);
        if (WIFEXITED(wstatus))
            g_last_status = WEXITSTATUS(wstatus);
        else
            g_last_status = wstatus;
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
