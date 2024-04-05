#include "shell.h"
/**
 *_strdup- function that duplicates a string
 *@str: string to be copied
 *Return:NULL if insufficient memory available
 */

char *_strdup(const char *str)
{
	char *duplicate;
	int index, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}

	str = str - len;
	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);
	for (index = 0; index <= len; index++)
		duplicate[index] = str[index];

	return (duplicate);
}
