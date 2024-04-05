#include "shell.h"

/**
 * _strcpy - copys a string
 * @dest: param1.  destination string argument
 * @src: param2. source string argument
 * Return: char string
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;

	}
	dest[i] = '\0';
	return (dest);
}
