#include "shell.h"
/**
 * get_environ - gets the value of an environment variable.
 * @var:environment variable.
 * Return: The value of the environment variable or NULL if not found.
 */
char *get_environ(char *var)
{
	char *temp, *key, *value,*path_value, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);

		key = strtok(temp, "=");

		if (_strcmp(key, var) == 0)
		{
			if (_strcmp(var, "PATH") == 0)
			{
				path_value = get_path();
				env = _strdup(path_value);
				free(temp);
				return (env);
			}
			else
			{
				value = strtok(NULL, "\n");
			}
			env = _strdup(value);
			free(temp);
			return (env);
		}
		free(temp);
		temp = NULL;
	}
	return (NULL);
}
