#include "shell.h"
/**
 *_strdup- function that returns a pointer to a newly allocated space in memory
 *contains a copy of the string given as a parameter.
 *@str: string to be copied
 *Return:NULL if insufficient memory available
 */


char *_strdup(const char *str)
{
	char *duplicate;
	int index, len = 0;

	if (str == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		len++;
	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
	{
		duplicate[index] = str[index];
	}

	duplicate[len] = '\0';

	return (duplicate);

}
