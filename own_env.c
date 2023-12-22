#include "shell.h"

/**
 * own_env - prints environment variables
 * @args: arguments
 *
 * Return: -1 if succesful, 0 if else
 */

int own_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
