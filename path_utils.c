#include "simpleshell.h"
#include <sys/stat.h>

/**
 * get_path_env - gets the PATH environment variable
 *
 * Return: pointer to the PATH string (not duplicated), or NULL if not found
 */
char *get_path_env(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
			return (environ[i] + 5);
	}
	return (NULL);
}

/**
 * search_path_for_cmd - looks for the full path of a command in PATH
 * @cmd: the command name
 * @path_dup: a duplicated PATH string
 *
 * Return: malloc'd string with full path if found, or NULL
 */
char *search_path_for_cmd(char *cmd, char *path_dup)
{
	char *token, *full_path;
	struct stat st;
	size_t len;

	token = strtok(path_dup, ":");
	while (token != NULL)
	{
		len = _strlen(token) + _strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
			return (NULL);

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}

