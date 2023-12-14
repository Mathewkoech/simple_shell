#include "shell.h"

/**
 *builtin - checks if command is shell builtin
 *@command: command to be checked
 *Return: 1 if the command is a builtin, 0 otherwise.
 */
int builtin(char *command)
{
	int i;

	char *builtins[] = {
			"setenv", "env", "exit",
			"cd", "echo", NULL};
	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 *handle_builtins-checks builtin functions
 *@cmd:command
 *@status:status of command
 *@argv:command line arguments
 *@i:index of command
 */

void handle_builtins(char **cmd, char **argv, int *status, int i)
{
	(void)i;
	(void)argv;
	if (_strcmp("exit", cmd[0]) == 0)
	{
		hsh_exit(cmd[0]);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		print_environ(cmd, status);
	}
	else if (_strcmp(cmd[0], "cd") == 0)
	{
		_cd(cmd);
	}
	else if (_strcmp(cmd[0], "echo") == 0)
	{
		_echo(cmd);
	}
}



/**
 * hsh_exit - terminates the prog with "exit" input.
 * @s: param. the string to be read.
 * Return: nothing.
 */

int hsh_exit(char *s)
{
	if (_strcmp("exit", s) == 0)
	{
		free(s);
		exit(EXIT_SUCCESS);
	}

	return (-1);
}
