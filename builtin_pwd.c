#include "simpleshell.h"

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

