#include "shell.h"

/**
 * is_interactive - tests wether the shell opens in interactive
 * or non-interactive mode
 *
 * Return: 0 if interactive, -1 if else
 */

int is_interactive(void)
{
	if (isatty(STDIN_FILENO))
	{
		return (0);
	}

	return (-1);
}
