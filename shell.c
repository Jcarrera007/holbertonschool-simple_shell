#include "simpleshell.h"

int main(void)
{
    /* Captura Ctrl+C */
    signal(SIGINT, handle_signal);

    /* Inicia el bucle principal */
    shell_loop();

    return EXIT_SUCCESS;
}

void shell_loop(void)
{
    char *line = NULL;
    char **args = NULL;
    size_t bufsize = 0;
    int status;

    do {
        print_prompt();
        if (getline(&line, &bufsize, stdin) == -1)
            break;             /* EOF (Ctrl+D) */

        args = split_line(line);
        status = execute(args);

        if (status)
            print_random_quote();

        free(args);
    } while (status);

    free(line);

}

void handle_signal(int sig)
{
    if (sig == SIGINT)
        printf("\n($) ");
}

