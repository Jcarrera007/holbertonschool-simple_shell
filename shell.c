#include "simpleshell.h"

int main(void)
{
	shell_loop();
	return (0);
}

void shell_loop(void)
{
	char *line;
	char **args;
	int status = 1;

	do {
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		line = read_line();
		if (!line)
			break;
		args = split_line(line);
		if (args[0])
			status = execute_command(args);
		free(line);
		free_args(args);
	} while (status);
}
