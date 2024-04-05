#include "shell.h"
/**
 * main - entry
 * @argv: param 3. environment
 *@arc:count of arguments
 * Return: int 0 on success
 */
int main(int arc, char **argv)
{
	char *line, **commands = NULL;
	int status_ = 0,  index = 0;
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
		index++;
		commands = tokenizer(line);
		if (!commands)
			continue;
		if (is_builtin(commands[0]))
                        handle_builtins(commands, argv, &status_, index);
                else
                        status_ = execute_command(commands, argv, index); }
}
