#include "shell.h"

/**
 * hsh_cd - func to do cd's
 * @args: param
 * Return: int on success
 */

int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");

	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("lhsh: cd");

	}
	return (1);
}
