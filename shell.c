#include "simpleshell.h"

/*Globals declared*/
char           *g_prog_name;
unsigned int    g_line_count;

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
 * Prints banner, sets up signal handler,
 * then enters the shell loop.
 *
 * Return: EXIT_SUCCESS on normal exit
 */
 int main(int argc, char **argv)
 {
    (void)argc;
     g_prog_name  = argv[0];
     g_line_count = 0;
     
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
 * shell_loop - read/ex​ecute commands until EOF or exit built-in
 */
 void shell_loop(void)
 {
     char    *line    = NULL;
     char    **args   = NULL;
     size_t  bufsize  = 0;
     int     status;  /* we will use this below */
 
     while (1)
     {
         if (interactive())
             print_prompt();
 
         if (getline(&line, &bufsize, stdin) == -1)
             break;  /* EOF (Ctrl+D) */
 
         g_line_count++;
         args   = split_line(line);
         status = execute(args);  /* status is now used */
         free(args);
 
         if (status == 0)
             break;               /* exit built-in signaled stop */
 
         if (interactive())
             print_random_quote();
     }
 
     free(line);
 }

/* handle_signal - takes SIGINT and redisplay prompt
 * @sig: the signal number */
 void handle_signal(int sig)
 {
     (void)sig;
     if (interactive())
         write(STDOUT_FILENO, "\n($) ", 6);
 }
