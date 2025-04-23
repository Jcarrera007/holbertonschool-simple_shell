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

