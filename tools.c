#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @str:string
 *
 * Return:integer
 */
int _atoi(char *str)
{
	int i, digit = 0;

	for (i = 0; str[i]; i++)
	{
		digit *= 10;
		digit += (str[i] - '0');
	}

	return (digit);
}
