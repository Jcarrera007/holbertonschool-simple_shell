#include "simpleshell.h"

/**
 * builtin_cat - muestra el contenido de un archivo
 * @args: array de argumentos, args[1] es el nombre de archivo
 *
 * Return: 1 siempre para continuar la ejecución del shell
 */

int builtin_cat(char **args)
{
	FILE *file;
	char buffer[BUFFER_SIZE];
	size_t n;

	if (args[1] == NULL)
	{
		fprintf(stderr, "cat: missing file operand\n");
		return (1);
	}

	file = fopen(args[1], "r");
	if (file == NULL)
	{
		perror("cat");
		return (1);
	}

	while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
	{
		fwrite(buffer, 1, n, stdout);
	}

	fclose(file);
	return (1);
}

