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
void error_print(char *name, char *command, int i)
{
	char message[] = ": not found\n";
	char *index;

	index = _itoa(i);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));

	free(index);
}

/**
 * _itoa - Converts an integer to a string.
 * @i: The integer
 *
 * Return: The string
 */
char *_itoa(int i)
{
	char buffer[20];
	size_t j = 0;

	if (i == 0)
		buffer[j++] = '0';
	else
	{

		while (i > 0 && j < (size_t)(sizeof(buffer) - 1))
		{
			buffer[j++] = (i % 10) + '0';
			i /= 10;
		}
	}

	buffer[j] = '\0';
	string_reverse(buffer, j);

	return (_strdup(buffer));
}

/**
 * _echo - Custom echo 
 * @cmd: Array of command arguments.
 */
void _echo(char **cmd)
{
	int i = 1;

	while (cmd[i] != NULL)
	{
		write(STDOUT_FILENO, cmd[i], _strlen(cmd[i]));
		if (cmd[i + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1);
		}
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}
