#include "simpleshell.h"

int execute(char **args)
{
    pid_t pid;
    int status;

    if (!args[0])
        return 1;

    if (strcmp(args[0], "cd") == 0)
        return builtin_cd(args);
    if (strcmp(args[0], "exit") == 0)
        return builtin_exit(args);
    if (strcmp(args[0], "pid") == 0)
        return builtin_pid(args);
    if (strcmp(args[0], "ls") == 0)
        return builtin_ls(args);
    if (strcmp(args[0], "cat") == 0)
        return builtin_cat(args);
    if (strcmp(args[0], "pwd") == 0)
        return builtin_pwd(args);

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
            perror("execvp");
        _exit(EXIT_FAILURE);
    }
    else if (pid < 0)
        perror("fork");
    else
        waitpid(pid, &status, 0);

    return 1;
}
