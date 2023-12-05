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
	int count = 0;
	int i = 0;

	if (!str)
	{
		return (NULL);
	}
	temp = strdup(str);

	token = strtok(temp, DELIM);
	if (!token)
	{
		free(str), str = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM)
	}
	free(temp), temp = NULL;

	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
	{
		free(str);
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	free(str);
	return (command);
}
