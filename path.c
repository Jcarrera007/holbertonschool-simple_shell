#include "simpleshell.h"

/**
 * get_full_path - busca la ruta completa de un comando en PATH
 * @cmd: nombre del comando
 *
 * Return: cadena malloced con la ruta completa o NULL si no existe
 */
char *get_full_path(char *cmd)
{
	char    *path_env = NULL;
	char    *path_dup;
	char    *token;
	char    *full_path;
	struct stat st;
	size_t  i;
	size_t  len_env, len;

	/* Obtener PATH desde environ */
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}
	if (path_env == NULL)
		return (NULL);

	/* Duplicar PATH para no alterar environ */
	len_env = _strlen(path_env) + 1;
	path_dup = malloc(len_env);
	if (path_dup == NULL)
		return (NULL);
	_strcpy(path_dup, path_env);

	/* Tokenizar y buscar el ejecutable */
	token = strtok(path_dup, ":");
	while (token != NULL)
	{
		/* Reservar espacio para "token/cmd\0" */
		len = _strlen(token) + 1 + _strlen(cmd) + 1;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path_dup);
			return (NULL);
		}

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			free(path_dup);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL);
}
