#include "shell.h"
/**
  * hsh_exit -  exit  shell
  * @command: command
  * @argv: command line arguments
  * @status: shell status
  * @index: index of the command input
  */

void hsh_exit(char **command, char **argv, int *status, int index)
{
	char *str_index, mess_error[] = ": exit: number not found: ";
	int value = (*status);

	if (command[1])
	{
		if (positive(command[1]))
		{
			value = _atoi(command[1]);
		}

		else
		{
			str_index = _itoa(index);
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, str_index, _strlen(str_index));
			write(STDERR_FILENO, mess_error, _strlen(mess_error));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(str_index);
			freecommand(command);
			(*status) = 2;
			return;
		}
	}
	freecommand(command);
	exit(value);
}
