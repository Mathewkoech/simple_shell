#include "shell.h"

/**
 * main - entry
 * @argc: param 1. argument count
 * @argv: param 2. argument list/vector
 * @envp: param 3. environment
 * Return: int 0 on success
 */

int main(int argc, char **argv, char **env_)
{
	char *line;
	char **args;

	do {
		_prompt();
		line = readline();
		args = tokenizer(line);
		status_ = hsh_exec(argv, env_);
	} while (status_);

	return (0);
}
