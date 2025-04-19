#include "simpleshell.h"

char *get_full_path(char *cmd)
{
	char *path = getenv("PATH");
	char *token, *full_path;
	struct stat st;

	token = strtok(path, ":");
	while (token)
	{
		full_path = malloc(_strlen(token) + _strlen(cmd) + 2);
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);
		if (stat(full_path, &st) == 0)
			return (full_path);
		token = strtok(NULL, ":");
		free(full_path);
	}
	return (NULL);
}
