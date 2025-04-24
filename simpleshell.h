#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

/*
 * ASCII ART PARA INICIO Y CIERRE DEL SHELL
 */
#define SHELL_ART \
"\n" \
"        ____  ____      ____ \n" \
"       |    ||    |    |    |\n" \
"       |    ||    |    |    |\n" \
"       |    ||    |    |    |\n" \
" ____  |    ||    |    |    |\n" \
"|    | |    ||    |    |    |\n" \
"|    | |    ||\\    \\  /    /|\n" \
"|\\____\\|____|| \\ ___\\/___ / |\n" \
"| |    |    | \\ |   ||   | / \n" \
" \\|____|____|  \\|___||___|/  \n" \
"    \\(   )/      \\(    )/    \n" \
"     '   '        '    '     \n" \
"                              \n"

/* Librerías permitidas */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 1024

extern char **environ;
extern char *g_prog_name;
extern unsigned int g_line_count;


/* Prototipos de built-ins */
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_pid(char **args);
int builtin_ls(char **args);
int builtin_cat(char **args);
int builtin_pwd(char **args);
int builtin_joke(char **args);

/* Prototipos del núcleo del shell */
int execute(char **args);
void shell_loop(void);
void print_prompt(void);
char *read_line(void);
char **split_line(char *line);
void print_error(char *prog_name, char *cmd, unsigned int line_count);

/* Manejador de señales */
void handle_signal(int sig);

/* Utilidades */
void list_dir(const char *path);
void print_random_quote(void);

/* Wrappers de <string.h> */
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

#endif /* SIMPLESHELL_H */
