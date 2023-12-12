#include "shell.h"

/**
 * hsh_myprintf - function to print.
 * @s: param. pointer to string
 * Return: void
 */

void hsh_myprintf(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}
