#include "shell.h"

/**
 *get_path- handles the path
 *
 *
 */
char *get_path(char *command)
{
	char *full_path, *dir;
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
}

