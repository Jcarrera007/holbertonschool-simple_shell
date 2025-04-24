#include "simpleshell.h"

/**
 * find_path_env - retrieves the PATH environment variable
 *
 * Return: pointer to PATH string or NULL if not set
 */
static char *find_path_env(void)
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
 * find_in_directory - checks if cmd exists in dir and builds path
 * @dir: directory path
 * @cmd: command name
 *
 * Return: malloced full path if exists, NULL otherwise
 */
static char *find_in_directory(char *dir, char *cmd)

{
	char *full_path;
	size_t len;
	struct stat st;

	len = _strlen(dir) + 1 + _strlen(cmd) + 1;
	full_path = malloc(len);
	if (full_path == NULL)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);

	if (stat(full_path, &st) == 0)
		return (full_path);

	free(full_path);
	return (NULL);
}

/**
 * get_full_path - searches each PATH directory for cmd
 * @cmd: command name
 *
 * Return: malloced path string or NULL if not found
 */
char *get_full_path(char *cmd)
{
	char *path_env;
	char *path_dup;
	char *token;
	char *result;

	path_env = find_path_env();
	if (path_env == NULL)
		return (NULL);

	path_dup = malloc(_strlen(path_env) + 1);
	if (path_dup == NULL)
		return (NULL);
	_strcpy(path_dup, path_env);

	token = strtok(path_dup, ":");
	while (token != NULL)
	{
		result = find_in_directory(token, cmd);
		if (result != NULL)
		{
			free(path_dup);
			return (result);
		}
		token = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL);
}
