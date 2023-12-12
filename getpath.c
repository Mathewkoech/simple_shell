#include "shell.h"
/**
 * check_path - Checks if the command is an absolute path.
 * @command: The command to check.
 *
 * Return: string representing the full path,
 *         or NULL on error
 */
char *check_path(char *command)/*checks if it is absolute path*/
{
	struct stat file_info;

	if (command[0] == '/')
	{
		if (stat(command, &file_info) == 0)
		{
			return (strdup(command));
		}
	}
	return (NULL):
}

/**
 * get_path - Searches for the command in the directories specified by PATH.
 * @command: The command to search for.
 *
 * Return: string representing the full path,
 *         or NULL or on error.
 */
char *get_path(char *command)
{
	char *path_env, *full_path, *dir;

	if (check_path(command))
	{
		return (strdup(command));
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
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path_env);
			return (full_path);
		}
		free(full_path);
	}
	free(path_env);
	return (NULL);
}
