#include "shell.h"
/**
*_setenv-Initialize a new environment variable, or modify an existing
*@args: array of arguments
*/
void _setenv(char **args)
{
	int i, j, k;
	int len1, len2;
	char *concatenate;

	if (!args[1] || !args[2])
	{
		perror("Missing variable value");
		return;
	}
	if (args[2] == NULL)
	{
		perror("Variable value is null");
		return;
	}
	len1 = _strlen(args[1]);
	len2 = _strlen(args[2]);
	concatenate = malloc(len1 + len2 + 2);

	if (!concatenate)
	{
		perror("Failed memory allocate");
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;
				j++;
			}
			if (args[1][j] == '\0')
			{
				k = 0;
				while (args[2][k])
				{
					environ[i][j + 1 + k] = args[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		_strcpy(concatenate, args[1]);
		_strcat(concatenate, "=");
		_strcat(concatenate, args[2]);
		environ[i] = concatenate;
		environ[i + 1] = NULL;
	}
}

/**
*_unsetenv-Initialize a new environment variable, or modify an existing
*@args: array of arguments passed
*/

void _unsetenv(char **args)
{
	int i, j;

	if (!args[1])
	{
		perror("setenv: Variable is null");
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (args[1][j] == environ[i][j])
		{
			while (args[1][j])
			{
				if (args[1][j] != environ[i][j])
					break;
				j++;
			}
			if (args[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
