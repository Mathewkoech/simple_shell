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
	int count = 0, i = 0, j = 0;

	if (!str)
		return (NULL);
<<<<<<< HEAD
	}
=======

>>>>>>> e6dd2b0d48430505a4bdb85d5abc4b58fc4f1950
	temp = strdup(str);
	token = strtok(temp, DELIM);
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(temp);
	command = malloc(sizeof(char *) * (count + 1));
	if (!command)
		return (NULL);
<<<<<<< HEAD
=======

>>>>>>> e6dd2b0d48430505a4bdb85d5abc4b58fc4f1950
	token = strtok(str, DELIM);
	if (!token)
	{
		free(command);
		return (NULL);
	}
	while (token)
	{
		command[i] = strdup(token);
		if (!command[i])
<<<<<<< HEAD
		{
=======
		{																			{
>>>>>>> e6dd2b0d48430505a4bdb85d5abc4b58fc4f1950
			for (j = 0; j < i; ++j)
				free(command[j]);
			free(command);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;
	return (command);
}
