#include "simpleshell.h"

int builtin_cd(char **args)
{
    if (!args[1])
        fprintf(stderr, "expected argument\n");
    else if (chdir(args[1]) != 0)
        perror("chdir");
    return 1;
}

int builtin_exit(char **args)
{
    (void)args;

    printf("\n");
    printf("  _     _  _ __      _____     _____    \n");
    printf(" /_/\\ /\\_/\\/_ \\ \\    / ___ \\   /\\ __/\\   \n");
    printf(" ) ) ) ( (  ) ) )  / /\\_/\\ \\  ) )  \\ \\  \n");
    printf("/_/ / \\ \\_\\/ / /  / /_/ (_\\ \\/ / /\\ \\ \\ \n");
    printf("\\ \\ \\_/ / /\\ \\ \\_ \\ \\ )_/ / /\\ \\ \\/ / / \n");
    printf(" \\ \\   / /  ) )__/\\\\ \\/_\\/ /  ) )__/ /  \n");
    printf("  \\_\\_/_/   \\/___\\/ \\ ____/   \\/___\\/   \n");
    printf("                                         \n");

    printf("Chequeamos <3\n\n");
    exit(EXIT_SUCCESS);
}

int builtin_pid(char **args)
{
    (void)args;
    printf("PID: %d\n", getpid());
    return 1;
}

int builtin_pwd(char **args)
{
    char cwd[BUFFER_SIZE];
    (void)args;

    if (getcwd(cwd, sizeof(cwd)))
        printf("%s\n", cwd);
    else
        perror("pwd");
    
    return 1;
}

int builtin_ls(char **args)
{
    DIR *dir;
    struct dirent *entry;
    char *dir_path = args[1] ? args[1] : ".";

    dir = opendir(dir_path);
    if (!dir)
    {
        perror("ls");
        return 1;
    }

    while ((entry = readdir(dir)))
        printf("%s  ", entry->d_name);

    printf("\n");
    closedir(dir);
    return 1;
}

int builtin_cat(char **args)
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t n;

    if (!args[1])
    {
        fprintf(stderr, "cat: missing file operand\n");
        return 1;
    }

    file = fopen(args[1], "r");
    if (!file)
    {
        perror("cat");
        return 1;
    }

    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
        fwrite(buffer, 1, n, stdout);

    fclose(file);
    return 1;
}
