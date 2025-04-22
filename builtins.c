#include "simpleshell.h"

/**
 * builtin_cd - cambia el directorio de trabajo
 * @args: array de argumentos, args[1] es el directorio destino
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */
int builtin_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument\n");
    }
    else if (chdir(args[1]) != 0)
    {
        perror("Equivocau");
    }

    return (1);
}

/**
 * builtin_exit - imprime arte de despedida y sale del shell
 * @args: array de argumentos (no usado)
 *
 * Exit: termina el proceso con EXIT_SUCCESS
 */
int builtin_exit(char **args)
{
    (void)args;

    printf("\n");
    printf("%s", SHELL_ART);
    fflush(stdout);
    printf("Chequeamos <3\n\n");
    exit(EXIT_SUCCESS);
}

/**
 * builtin_pid - imprime el PID del proceso actual
 * @args: array de argumentos (no usado)
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */
int builtin_pid(char **args)
{
    (void)args;

    printf("PID: %d\n", getpid());
    return (1);
}

/**
 * builtin_pwd - imprime el directorio de trabajo actual
 * @args: array de argumentos (no usado)
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */
int builtin_pwd(char **args)
{
    char cwd[BUFFER_SIZE];

    (void)args;

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        perror("pwd");

    return (1);
}

/**
 * builtin_ls - lista el contenido de un directorio
 * @args: array de argumentos, args[1] es el directorio (o "." por defecto)
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */
int builtin_ls(char **args)
{
    DIR *dir;
    struct dirent *entry;
    char *dir_path = (args[1] != NULL) ? args[1] : ".";

    dir = opendir(dir_path);
    if (dir == NULL)
    {
        perror("ls");
        return (1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s  ", entry->d_name);
    }

    printf("\n");
    closedir(dir);
    return (1);
}

/**
 * builtin_cat - muestra el contenido de un archivo
 * @args: array de argumentos, args[1] es el nombre de archivo
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */
int builtin_cat(char **args)
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t n;

    if (args[1] == NULL)
    {
        fprintf(stderr, "cat: missing file operand\n");
        return (1);
    }

    file = fopen(args[1], "r");
    if (file == NULL)
    {
        perror("cat");
        return (1);
    }

    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        fwrite(buffer, 1, n, stdout);
    }

    fclose(file);
    return (1);
}
