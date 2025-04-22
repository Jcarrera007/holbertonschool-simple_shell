#include "simpleshell.h"

/**
 * split_line - tokeniza una línea de entrada en un array de cadenas
 * @line: cadena que contiene la línea de entrada
 *
 * Return: array de punteros a tokens, terminado en NULL
 */
char **split_line(char *line)
{
    int bufsize = BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (tokens == NULL)
    {
        perror("shell: malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (tokens == NULL)
            {
                perror("shell: realloc");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;

    return (tokens);
}
