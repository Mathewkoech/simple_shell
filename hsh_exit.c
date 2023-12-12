#include "shell.h"

/**
 * hsh_exit - terminates the prog with "exit" input.
 * @s: param. the string to be read.
 * Return: nothing.
 */

void hsh_exit(char *s)
{
	if (_strcmp("exit", s) == 0)
	{
		free(s);
		exit(EXIT_SUCCESS);
	}
}
