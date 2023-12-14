 #include "shell.h"

/**
 * read_line - Read a line of input
 *
 * Return: pointer to the read line.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "_$ ", 3);
	}

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	if (line[read - 1] == '\n')
	{
		line[read - 1] = '\0';
	}
	if (line[0] == '#' && (line[1] == '\0' || line[1] == ' '))
	{
		free(line);
		return (read_line());
	}
	return (line);
}
