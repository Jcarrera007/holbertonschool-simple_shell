#include "simpleshell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t n = getline(&line, &bufsize, stdin);

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
    return line;
}
