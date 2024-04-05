#include "shell.h"
/**
 * string_reverse - Reverses a string
 * @str: The string
* @lenght: The length of the string.
 */

void string_reverse(char *str, int lenght)
{
	char ptr;
	int first = 0;
	int last = lenght - 1;

	while (first < last)
	{
		ptr = str[first];
		str[first] = str[last];
		str[last] = ptr;
		first++;
		last--;
	}
}
