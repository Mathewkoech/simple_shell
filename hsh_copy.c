#include "shell.h"

/**
 * _strcpy - copys a string
 * @dest: param1.  destination string argument
 * @src: param2. source string argument
 * Return: char string
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
