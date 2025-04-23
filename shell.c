#include "simpleshell.h"

/**
 * main - entry point for JV Shell
 *
 * Return: EXIT_SUCCESS to indicate successful execution
 */
int main(void)
{
	/* Print ASCII art and welcome message */
	printf("%s", SHELL_ART);
	printf("El JV Shell 🌴\n\n");
	fflush(stdout);

	/* Handle Ctrl+C (SIGINT) */
	signal(SIGINT, handle_signal);

	/* Start the main shell loop */
	shell_loop();

	return (EXIT_SUCCESS);
}

/**
 * shell_loop - main loop for reading and executing commands
 *
 * Return: void
 */
void shell_loop(void)
{
	char *line = NULL;
	char **args;
	size_t bufsize = 0;
	int status;

	do {
		print_prompt();
		if (getline(&line, &bufsize, stdin) == -1)
			break; /* EOF or read error */

		args = split_line(line);
		status = execute(args);

		if (status)
			print_random_quote();

		free(args);
	} while (status);

	free(line);
}

/**
 * handle_signal - handles SIGINT (Ctrl+C) gracefully
 * @sig: signal number (should be SIGINT)
 *
 * Return: void
 */
void handle_signal(int sig)
{
	(void)sig;
	printf("\n($) ");
}

