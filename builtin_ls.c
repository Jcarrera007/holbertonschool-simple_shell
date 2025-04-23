#include "simpleshell.h"

/**
 * builtin_ls - lista el contenido de un directorio
 * @args: array de argumentos, args[1] es el directorio (o "." por defecto)
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */

int builtin_ls(char **args)
{
	DIR *dir;
	struct dirent *entry;
	char *dir_path = (args[1] != NULL) ? args[1] : ".";

	dir = opendir(dir_path);
	if (dir == NULL)
	{
		perror("ls");
		return (1);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		printf("%s  ", entry->d_name);
	}
	printf("\n");
	closedir(dir);
	return (1);
}

