#include "shell.h"
/**
 * tokenizer - Tokenizes a string into an array of strings.
 * @str: The string to tokenize.
 * Return: An array of strings (tokens), or NULL on failure.
*/

char **tokenizer(char *str)
{
	char *token = NULL, *temp = NULL;
	char **command = NULL;
	int count = 0, i = 0;

	if (!str)
		return (NULL);
	temp = _strdup(str);
	token = strtok(temp, DELIM);
	if (token == NULL)
	{
		free(str), str = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(temp);
	temp = NULL;
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(str), str = NULL;
		return (NULL);
	}
	token = strtok(str, DELIM);
	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	free(str);
	return (command);
}
