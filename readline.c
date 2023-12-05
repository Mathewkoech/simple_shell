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
	    write(STDOUT_FILENO, "$ ", 2);
    }

    read = getline(&line, &len, stdin);

    if (read == -1)
    {
        free(line);
        return (NULL);
    }

    return (line);
}
