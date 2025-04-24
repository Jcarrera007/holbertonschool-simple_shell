#include "simpleshell.h"

/**
 * print_error - prints an error when a command is not found
 * @prog_name: name of the shell program
 * @cmd: command that was not found
 * @count: command invocation count
 *
 * Return: void
 */
void print_error(char *prog_name, char *cmd, unsigned int line_count)
{
	fprintf(stderr, "%s: %u: %s: not found\n",
		prog_name, line_count, cmd);
}
