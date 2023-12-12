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

/**
 *error_print- prints error
 *@name:program name
 *@i:index
 *@command:command
 */
void error_print(char *name, int i, char *command)
{
	char message[] = ": not found\n";
	char *index;

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, mssg, _strlen(message));

	free(index);
}
