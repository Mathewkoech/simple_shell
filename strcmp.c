#include "shell.h"
/**
 * _strcmp - function that compares two strings
 * @s1: param 1. pointer to first string
 * @s2: parama 2. pointer to second string
 * Return: int val
 */

int _strcmp(char *s1, char *s2)
{
	int comp;

	comp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		comp = (int)*s1 - (int)*s2;
	}
	return (comp);
}
