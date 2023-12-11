#include "shell.h"

/**
 * _strlen - length of a string
 * @s: param. string
 * Return: int string length
 */

int _strlen(char *s)
{
	int i = 0;

	for (i = 0; *(s + i) != '\0'; i++)
		;

	return (i);
}
