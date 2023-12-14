#include "shell.h"
/**
 * var_replace - Replaces variables in a string.
 * @str: The input string.
 * @status: exit status to replace $?.
 * @pid: process ID to replace $$.
 * Return: string with replaced variables.
 */
char *var_replace(char *str, int status, pid_t pid)
{
	char *result = NULL;
	char *str_status = _itoa(status), *pid_str = _itoa((int)pid);

	if (str_status == NULL || pid_str == NULL)
	{
		free(str_status);
		free(pid_str);
		return (NULL);
	}
	result = str_rep(str, "$?", str_status);
	if (result == NULL)
	{
		free(str_status);
		free(pid_str);
		return (NULL);
	}
	free(str);
	str = result;
	result = str_rep(str, "$$", pid_str);
	if (result == NULL)
	{
		free(str_status);
		free(pid_str);
		return (NULL);
	}
	free(str_status);
	free(pid_str);
	return (result);
}
/**
 * str_rep - Replace all occurrences of a substring in a string.
 * @str: string.
 * @old: substring to replace.
 * @new: replacement string.
 * Return: A newly allocated string
 */
char *str_rep(const char *str, const char *old, const char *new)
{
	char *result;
	int new_len = _strlen(new), count = 0, i = 0, old_len = _strlen(old);

	for (i = 0; str[i] != '\0'; ++i)
	{
		if (_strstr(&str[i], old) == &str[i])
		{
			++count;
			i += old_len - 1;
		}
	}
	result = (char *)malloc(i + count * (new_len - old_len) + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (*str)
	{
		if (_strstr(str, old) == str)
		{
			_strcpy(&result[i], new);
			i += new_len;
			str += old_len;
		}
		else
		{
			result[i++] = *str++;
		}
	}
	result[i] = '\0';
/*	free(result);*/
	return (result);
}
