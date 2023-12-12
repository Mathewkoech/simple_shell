#include "shell.h"

/**
 * main - entry
 * @envp: param 3. environment
 * Return: int 0 on success
 */

int main(char **envp)
{
	char *line;
	char **args;
	int status_;

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
