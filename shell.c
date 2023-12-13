#include "shell.h"

/**
 * main - entry
 * @envp: param 3. environment
 *@arc:count of arguments
 * Return: int 0 on success
 */
int main(int arc, char **envp)
{
	char *line;
	char **args;
	int i = 0;
	int status_;
	(void)arc;

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
		args = tokenizer(line);
		if (!args)
			continue;
		if (builtin(args[0]))
		{
			handle_builtins(args, envp, &status_, i);
		}
		else
			status_ = execute_command(args, envp, i);
	}
	return (0);
}
