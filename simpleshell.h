#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

/* ASCII ART PARA INICIO*/
#define SHELL_ART "\n" \
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

/*Resto de librerias*/
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
#include <time.h>

#define BUFFER_SIZE 1024

/* Built-in command prototypes */
int builtin_cd(char **args);
int builtin_exit(char **args);
int builtin_pid(char **args);
int builtin_ls(char **args);
int builtin_cat(char **args);
int builtin_pwd(char **args);
void builtin_env(void);

/* Shell function prototypes */
void handle_signal(int sig);
void print_prompt(void);
int execute(char **args);
void shell_loop(void);
char *read_line(void);
char **split_line(char *line);

/* String helper wrappers */
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char **split_line(char *line);


/* Utilities */
void list_dir(const char *path);
void print_random_quote(void);

extern char **environ;

#endif /* SIMPLESHELL_H */
