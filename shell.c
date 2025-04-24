#include "simpleshell.h"

/**
 * interactive - returns non-zero if stdin is a terminal
 *
 * Return: 1 if interactive, 0 otherwise
 */
static int interactive(void)
{
    return (isatty(STDIN_FILENO));
}

/**
 * main - entry point for the shell
 *
 * Prints banner only in interactive mode, sets up signal handler,
 * then enters the shell loop.
 *
 * Return: EXIT_SUCCESS on normal exit
 */
int main(void)
{
    if (interactive())
    {
        /* banner only when run from a real terminal */
        printf("%s", SHELL_ART);
        printf("El JV Shell 🌴\n\n");
        fflush(stdout);
    }

    signal(SIGINT, handle_signal);
    shell_loop();

    return (EXIT_SUCCESS);
}

/**
 * shell_loop - read, execute, repeat until EOF
 *
 * In interactive mode prints a prompt before each command and
 * a random Jovani quote afterward. Suppresses all of that when
 * stdin is not a TTY.
 */
void shell_loop(void)
{
    char    *line    = NULL;
    char    **args   = NULL;
    size_t  bufsize = 0;
    int     status;

    while (1)
    {
        if (interactive())
            print_prompt();

        if (getline(&line, &bufsize, stdin) == -1)
            break; /* EOF (Ctrl+D) */

        args   = split_line(line);
        status = execute(args);
        free(args);

        if (status && interactive())
            print_random_quote();
    }

    free(line);
}

/**
 * handle_signal - catch SIGINT and redisplay prompt
 * @sig: signal number (should be SIGINT)
 */
void handle_signal(int sig)
{
    (void)sig;
    if (interactive())
        write(STDOUT_FILENO, "\n($) ", 6);
}
