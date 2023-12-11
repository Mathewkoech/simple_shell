#include "shell.h"

/**
 * _myprintf - function to print.
 * @s: param. pointer to string
 * Return: void
 */

void _myprintf(const char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
}
