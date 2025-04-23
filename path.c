#include "simpleshell.h"

/**
 * get_full_path - builds full path of a command by searching PATH
 * @cmd: command name
 *
 * Return: malloc'd string with full path, or NULL if not found
 */
char *get_full_path(char *cmd)
{
	char *path_env, *path_dup, *full_path;
	size_t len_env;

	path_env = get_path_env();
	if (path_env == NULL)
		return (NULL);

	len_env = _strlen(path_env) + 1;
	path_dup = malloc(len_env);
	if (path_dup == NULL)
		return (NULL);

	_strcpy(path_dup, path_env);
	full_path = search_path_for_cmd(cmd, path_dup);
	free(path_dup);
	return (full_path);
}

