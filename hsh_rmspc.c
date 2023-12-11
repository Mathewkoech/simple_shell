#include "shell.h"

/**
 * rmspace- remove space
 * @cmd: param. comand to edit
 * Return: char
 */

char *rmspace(char *cmd)
{
	char *cpcmd;
	int i, len;

	for (i = 0; cmd[i] == ' '; ++i)
	{
		;
	}

	len = _strlen(cmd) - i + 1;
	cpcmd = malloc(len + 1);
	if (cpcmd == NULL)
	{
		perror("Memory Allocation Failed\n");
		return (NULL);
	}
	_strncpy(cpcmd, cmd + i, len);
	cpcmd[len] = '\0';
	_strcpy(cmd, cpcmd);
	free(cpcmd);
	return (cmd);
}
