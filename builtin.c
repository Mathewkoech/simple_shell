#include "shell.h"

/**
 *is_builtin - checks if command is shell builtin
 *@command: command to be checked
 *Return: 1 if the command is a builtin, 0 otherwise.
 */
int is_builtin(char *command)
{
	int i;

	char *builtins[] = {
			"setenv", "env", "exit",
			"cd", "unsetenv", NULL};
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
		hsh_exit(cmd, argv, status, i);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		print_environ(cmd, status);
	}
	else if (_strcmp(cmd[0], "setenv") == 0)
	{
		_setenv(cmd);
	}
	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		_unsetenv(cmd);
	}
}
