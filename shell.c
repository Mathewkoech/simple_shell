#include "shell.h"

/**
 * main - entry
 * @argc: param 1. argument count
 * @argv: param 2. argument list/vector
 * @envp: param 3. environment
 * Return: int 0 on success
 */

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **args;

	do {
		_prompt();
		line = read_line();
		args = tokenizer(line);

		if (args[0] != NULL)
			status_ = hsh_exec(args, envp);

		free(line);
		free(args);
	} while (status_);

	return (0);
}
