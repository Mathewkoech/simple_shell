/**
 * execute_command - Executes the given command using execve.
 * @command: The command to execute.
 *@argv:vector arguments
 *@index:index of command
 * Return: void
 */
void execute_command(char **command, int index, Char **argv)
{
	pid_t child_pid;
	char *full_path;

	full_path = get_path(command);

	if (full_path)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(full_path);
			freecommand(command);
			return;
		}

		if (child_pid == 0)
		{
			if (execve(full_path, (command, environ) == -1)
			{
				perror("execve");
				freecommand(command);
				free(full_path);
				exit(EXIT_FAILURE);
			}
				}
			else
			{
				int status;

				waitpid(child_pid, &status, 0);
				if (WIFEXITED(status))
				{
					return (WEXITSTATUS(status));
				}
				else
				{
					perror("Did not terminate normally");
					return (-1);
				}
			}
			free(full_path);
		}
		else
		{
			error_print(argv[0], command, index);
		}
	}
}
