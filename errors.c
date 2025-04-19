#include "simpleshell.h"

void print_error(char *prog_name, char *cmd, int count)
{
	fprintf(stderr, "%s: %d: %s: not found\n", prog_name, count, cmd);
}
