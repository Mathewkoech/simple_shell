#include "shell.h"

/**
  * execute_command - function to execute user commands
  * @command: user commands array
  * @argv: argument
  * @idx_num: index number of the command
  * Return: execution status
  */

int execute_command(char **command, char **argv, int idx_num)
{
	char *full_path;
	pid_t child_process;
	int status;

	full_path = get_path(command[0]);
	if (!full_path)
	{
		error_print(argv[0], command[0], idx_num);
		freecommand(command);
		return (127);
	}

	child_process = fork();
	if (child_process == -1)
	{
		perror("fork");
		free(full_path);
		freecommand(command);
		return (-1);
	}

	if (child_process == 0)
	{
		if (execve(full_path, command, environ) == -1)
		{
			perror("execve");
			free(full_path);
			freecommand(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_process, &status, 0) == -1)
		{
			perror("waitpid");
			free(full_path);
			freecommand(command);
			return (-1);
		}
	}

	freecommand(command);
	free(full_path);

	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else
	{
		perror("Child process did not terminate normally");

		return (-1);
	}
}
