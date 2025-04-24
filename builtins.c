#include "simpleshell.h"

/**
 * builtin_cd - changes the current working directory
 * @args: array of arguments, args[1] is the target directory
 *
 * Return: 1 to continue shell loop
 */
int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument\n");
	}
	else if (chdir(args[1]) != 0)
	{
		perror("Equivocau");
	}

	return (1);
}

/**
 * builtin_exit - prints exit art and exits the shell
 * @args: array of arguments (unused)
 *
 * Exit: terminates the process with EXIT_SUCCESS
 */
int builtin_exit(char **args)
{
	(void)args;

	printf("\n");
	printf("%s", SHELL_ART);
	fflush(stdout);
	printf("Chequeamos <3\n\n");
	exit(EXIT_SUCCESS);
}

/**
 * builtin_pid - prints the process ID of the shell
 * @args: array of arguments (unused)
 *
 * Return: 1 to continue shell loop
 */
int builtin_pid(char **args)
{
	(void)args;

	printf("PID: %d\n", getpid());
	return (1);
}

/**
 * builtin_pwd - prints the current working directory
 * @args: array of arguments (unused)
 *
 * Return: 1 to continue shell loop
 */
int builtin_pwd(char **args)
{
	char cwd[BUFFER_SIZE];

	(void)args;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("pwd");
	}

	return (1);
}
/**
 * builtin_ls - lists the contents of a directory
 * @args: array of arguments, args[1] is directory path or NULL for current
 *
 * Return: 1 to continue shell loop
 */
int builtin_ls(char **args)
{
	DIR *dir;
	struct dirent *entry;
	char *dir_path;

	if (args[1] != NULL)
		dir_path = args[1];
	else
		dir_path = ".";

	dir = opendir(dir_path);
	if (dir == NULL)
	{
		perror("ls");
		return (1);
	}

	while ((entry = readdir(dir)) != NULL)
		printf("%s  ", entry->d_name);

	printf("\n");
	closedir(dir);

	return (1);
}

/**
 * builtin_cat - displays the contents of a file
 * @args: array of arguments, args[1] is filename
 *
 * Return: 1 to continue shell loop
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
		fwrite(buffer, 1, n, stdout);

	fclose(file);
	return (1);
}

/**
 * builtin_joke - prints a random Jovani Vázquez quote
 * @args: array of arguments (unused)
 *
 * Return: 1 to continue shell loop
 */
int builtin_joke(char **args)
{
	(void)args;
	print_random_quote();
	return (1);
}
