#include "shell.h"
/**
 * string_reverse - Reverses a string
 * @str: The string
* @lenght: The length of the string.
 */

void string_reverse(char *str, int lenght)
{
	char temp;
	int first = 0;
	int last = lenght - 1;

	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}
