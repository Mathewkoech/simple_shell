#include "shell.h"

/**
 * hsh_help - function to privide help
 * Return: void
 */

void hsh_help(void)
{
	char *text_ =
		"hsh - the custom Shell. The following commands are built in:\n"
		"  cd       Change the working directory.\n"
		"  exit     Exit the shell.\n"
		"  help     Print this help text.\n";
	hsh_myprintf(text_);
}
