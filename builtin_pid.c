#include "simpleshell.h"

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

