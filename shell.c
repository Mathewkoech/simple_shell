#include "shell.h"
/**
 * main - entry
 * @envp: param 3. environment
 *@arc:count of arguments
 * Return: int 0 on success
 */
int main(int arc, char **envp)
{
	pid_t pid;
	char *line, **commands, **args;
	int status_, i = 0, cmd_index = 0;
	(void)arc;

	pid = getpid();
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(line);
			return (status_);
		}
		line = var_replace(line,status_, pid);
		commands = tokenizer(line);
		if (!commands)
			continue;
		for (cmd_index = 0; commands[cmd_index] != NULL; cmd_index++)
		{
			args = tokenizer(commands[cmd_index]);
			if (!args)
			continue;
			if (builtin(args[0]))
			{
				handle_builtins(args, envp, &status_, i);
			}
			else
			{
				status_ = execute_command(args, envp, i);
					}
			freecommand(args);
		}
		freecommand(commands);
	}
	return (0);
}
