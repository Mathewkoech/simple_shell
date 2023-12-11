#include "shell.h"

/**
 * _strncmp - compares n number of bytes in str1 and str2
 * @str1: param 1. first string to be compared
 * @str2: param 2. second string to be compared
 * @n: param 3. number of bytes to be compared.
 * Return: int. > 0 if str2 is less than str1, < 0 if str1 < str2,
 * 0 is str1 is equal to str2
 */

int _strncmp(char *str1, char *str2, int n)
{
	if (!n)
		return (0);

	if (*str1 == *str2)
		return (*str1 ? _strncmp(str1 + 1, str2 + 1, n - 1) : 0);

	if (*str1)
		return (1);
	if (*str2)
		return (-1);
	return (*str1 - *str2);
}
