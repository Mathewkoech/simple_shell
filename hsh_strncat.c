#include "shell.h"

/**
 * _strncat - Concantenates two strings accoring to n
 * @dest: param 1. detsination string
 * @src: param 2. source string.
 * @n: n number of bytes to copy from src.
 * Return: char Pointer to destination string.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
