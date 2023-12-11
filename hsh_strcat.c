#include "shell.h"

/**
 * _strcat - func appends the src string to the dest string
 * @dest: param 1.
 * @src: param 2. 
 * Return: char. String
 */

char *_strcat(char *dest, char *src)
{
	int len_s, len_d, j;

	for (len_s = 0; src[len_s] != '\0'; ++len_s)
	{
		;
	}

	for (len_d = 0; dest[len_d] != '\0'; ++len_d)
	{
		;
	}

	for (j = 0; j < len; j++)
		dest[len_d + j] = src[j];
	

	dest[len_d + len_s] = '\0';
	return (dest);
}
