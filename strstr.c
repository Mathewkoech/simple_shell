#include "shell.h"
/**
 *_strstr- searches a substring in string
 *@str:string to search in
 *@sub_str:substring to search for
 *Return:return pointer to first occurrence in str
 */
char *_strstr(const char *str, const char *sub_str)
{
	if (*sub_str == '\0')
	{
		return ((char *)str);
	}
	while (*str != '\0')
	{
		const char *s = str;
		const char *sbt = sub_str;

		while (*s != '\0' && *sbt != '\0' && *s == *sbt)
		{
			s++;
			sbt++;
		}
		if (*sbt == '\0')
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
