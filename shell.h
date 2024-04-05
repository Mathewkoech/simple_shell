#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#define DELIM " \t\n;"
extern char **environ;

void hsh_exit(char **command, char **argv, int *status, int index);
char *read_line(void);
void print_environ(char **command, int *status);
void freecommand(char **command);
char **tokenizer(char *str);
char *get_environ(char *var);
char *get_path(char *command);
void error_print(char *name, char *command, int i);
void _unsetenv(char **args);
void _setenv(char **args);
	
/**integers*/
char *_itoa(int i);
int _atoi(char *str);
int positive(char *str);

/** string manipulation*/
char *_strstr(const char *str, const char *sub_str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
void string_reverse(char *str, int lenght);
char *_strdup(const char *str);
char *_strcat(char *src, char *dest);
int _strlen(char *str);
char *concat_3_strings(char *s1, char *s2, char *s3);

/**execute*/
int execute_command(char **command, char **argv, int idx_num);
/**builtins*/
void handle_builtins(char **command, char **argv, int *status, int i);
int is_builtin(char *command);
#endif
