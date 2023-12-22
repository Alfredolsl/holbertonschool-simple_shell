#include "shell.h"

/**
 * forking - creates child process
 * @args: array of strings that contains the commands and its flags
 *
 * Return: 1 if successful, 0 otherwise
 */

int forking(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
			perror("error in forking.c: child process");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("error in forking.c: forking");
	else
	{
		/* parent process */
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
