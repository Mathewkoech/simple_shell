#include "shell.h"
/**
 *get_path- handles the path
 *@command:command
 *Return:string representing full path
 */
char *get_path(char *command)
{
	char *full_path, *dir, path_env;
	int i;
	struct stat file_info;

	for (i = 0; command[i]; i++)
	{
		if (command == '/')
		{
			if (stat(command, &file_info) == 0)
			{
				return (strdup(command));
			}
			return (NULL);
		}
	}
	path_env = get_environ("PATH");
	if (!path_env)
	{
		return (NULL);
	}

	for (dir = strtok(path_env, ":"); dir; dir = strtok(NULL, ":"))
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
		{
			free(path_env);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, '/');
		strcat(full_path, command);

		if (stat(full_path, &file_info) == 0)
		{
			free(path_env);
			return (full_path);
		}
		free(free_path);
	}
	free(path_env);
	return (NULL);
}
