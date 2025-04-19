#include "simpleshell.h"

char **split_line(char *line)
{
	int bufsize = BUFFER_SIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
		return (NULL);
	token = strtok(line, " 	\a");
	while (token)
	{
		tokens[position++] = _strdup(token);
		token = strtok(NULL, " 	\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
