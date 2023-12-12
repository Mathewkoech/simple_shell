#include "shell.h"

/**
 * hsh_exec - function to execute
 * @args: param1. arguments pointer array list
 * @env_: param2. environment
 * Return: void
 */

int hsh_exec(char **args, char **env_)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	/*child process */
	{
		/* execute the command in the child process */
		if (execvp(args[0], args, env_) == -1)
		{
			/**
			 * if execvp fails, print an error message,
			 * and exit the child process
			 * with a failure status
			 */
			perror("hsh. error");
			exit(1);
		}
	}
	else if (child_pid > 0)
	/* parent process */
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	}
	else
	{
		/*error forking*/
		perror("hsh.. error :( ");
	}
	return (1);
}
