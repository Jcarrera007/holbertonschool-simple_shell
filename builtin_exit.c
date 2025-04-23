#include "simpleshell.h"

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

