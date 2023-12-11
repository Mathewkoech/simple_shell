#include "shell.h"

/**
 * _strcmp - function that compares two strings
 * @s1: param 1. pointer to first string
 * @s2: parama 2. pointer to second string
 * Return: int val
 */

int _strcmp(char *s1, char *s2)
{
	int result_ = 0;

	while (*s1 == *s2 && *s1 != '\0')
		s1++, s2++;

	if (s1 != s2)
		result_ = *s1 - *s2;

	return (result_);
}
