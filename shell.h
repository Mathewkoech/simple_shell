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

#define DELIM " \t\n"
extern char **environ;

int _strlen(char *s);
int hsh_exec(char **args, char **env_);
int hsh_cd(char **args);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
void hsh_exit(char *s);
void hsh_myprintf(char *s);
void _prompt(void);
char *rmspace(char *cmd);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, const char *src, size_t n);
void hsh_help(void);
char *read_line(void);
void print_environ(char **command, int *status);
void freecommand(char **command);
char **tokenizer(char *str);
char *get_environ(char *var);
char *get_path(char *command);
char *check_path(char *command);
#endif
