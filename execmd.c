#include "shell.h"

/**
 * execmd - executes input
 * @argv: argument vector containing command
 *
 * Return: 0 if successful, otherwise 1
 */

int execmd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;
	pid_t child_pid;

	if (argv)
	{
		command = argv[0];

		actual_cmd = get_location(command);

		if (actual_cmd == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			return (1);
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(actual_cmd, argv, NULL) == -1)
			{
				perror("execve");
				return (1);
			}
		}

		else
		{
			int status;
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
