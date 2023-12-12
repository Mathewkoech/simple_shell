#include "shell.h"

/**
 *print_environ-prints enviroment variables
 *@command:command arguments for env
 *@status:exit status
 */

void print_environ(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freecommand(command);
	(*status) = 0;
}

/**
 *freecommand-freeing command arrays
 *@command:arrays freed
 */


void freecommand(char **command)
{
	int i;

	/*Free each  string in the array */
	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}
	free(command);
}
