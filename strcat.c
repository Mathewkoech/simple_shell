#include "shell.h"
/**
  * _strcat -concatenate 2 strings
  * @dest: destination string
  * @src: the source string
  * Return: the dest string
  */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	if (dest == NULL || src == NULL)
		return (dest);

	while (*s)
	{
		s++;
	}
	while (*src)
	{
		*s = *src;
		s++;
		src++;
	}
	*s = '\0';
	return (dest);
}
