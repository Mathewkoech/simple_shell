#include "shell.h"

/** main - entry
 * Return: int 0 on success
 */

int main(void) {
	char cmd[222];

	while (true) 
	{
		_prompt();
		read_(cmd, sizeof(command));
		execute_(cmd);						    
		}

	return (0);		
}
