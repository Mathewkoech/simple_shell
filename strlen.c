#include "shell.h"

/**
 * _strlen - length of a string
 * @str: param. string
 * Return: int string length
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}
