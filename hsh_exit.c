#include "shell.h"

/**
 * _exit - terminates the prog with "exit" input.
 * @s: param. the string to be read.
 * Return: nothing.
 */

void _exit(char *s)
{
	if (_strcmp("exit", s) == 0)
	{
		free(s);
		exit(EXIT_SUCCESS);
	}
}
