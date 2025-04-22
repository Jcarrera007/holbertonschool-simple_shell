#include "simpleshell.h"

/**
 * read_line - reads a line of input from stdin
 *
 * Return: pointer to the buffer containing the line (must be freed by caller)
 */
char *read_line(void)
{
    char   *line = NULL;
    size_t bufsize = 0;
    ssize_t n;

    n = getline(&line, &bufsize, stdin);
    if (n == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return (line);
}
