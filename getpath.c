#include "shell.h"
/**
 * get_path - Check the full path of a command.
 * @command: The command to check.
 *
 * Return: string representing the full path
 */
char *get_path(char *command)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}
	path_env = get_environ("PATH");
	if (!path_env)
		return (NULL);
	for (dir = strtok(path_env, ":"); dir; dir = strtok(NULL, ":"))
	{
		full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
		if (!full_cmd)
		{
			free(path_env);
			return (NULL);
		}
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, command);
		if (stat(full_cmd, &st) == 0)
		{
			free(path_env);
			return (full_cmd);
		}
		free(full_cmd);
	}
	free(path_env);
	return (NULL);
}
