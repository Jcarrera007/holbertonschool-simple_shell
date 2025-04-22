#include "simpleshell.h"

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	size_t bufsize = 0;
	int status;
	
	signal(SIGINT, handle_signal);

	do {
		print_prompt();
		getline(&line, &bufsize, stdin);
		args = split_line(line);
		status = execute(args);
		free(args);
	} while (status);
	
	free(line);
	
    return 0;
}

void handle_signal(int sig)
{
    if (sig == SIGINT)
        printf("\n($) ");
}

void print_prompt(void)
{
    char cwd[BUFFER_SIZE];
    if (getcwd(cwd, sizeof(cwd)))
        printf("%s ($) ", cwd);
    else
        perror("getcwd");
    fflush(stdout);
}
