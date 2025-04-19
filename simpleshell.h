#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define PROMPT "$ "
#define BUFFER_SIZE 1024

extern char **environ;

/* Core */
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
char *get_full_path(char *cmd);

/* Built-ins */
int handle_builtin(char **args);
void builtin_exit(char **args);
void builtin_env(void);

/* Utils */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
void free_args(char **args);
void print_error(char *prog_name, char *cmd, int count);

#endif /* MAIN_H */
