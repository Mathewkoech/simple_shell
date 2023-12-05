#include "shell.h"
/**
 *execute-executes the command
 *@argv:array of characters
 *
 */

void execute(char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
}
