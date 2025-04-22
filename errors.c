#include "simpleshell.h"

/**
 * print_error - imprime un mensaje de error cuando un comando no existe
 * @prog_name: nombre del programa (shell)
 * @cmd: comando que no se encontró
 * @count: número de la ejecución del comando
 *
 * Return: void
 */
void print_error(char *prog_name, char *cmd, int count)
{
	fprintf(stderr, "%s: %d: %s: not found\n",
			prog_name, count, cmd);
}
