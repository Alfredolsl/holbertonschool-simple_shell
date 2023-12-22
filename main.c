#include "shell.h"

/**
 * main - determines whether the shell is opened interactively
 * or non-interactively
 *
 * Return: 0 if successful
 */

int main(void)
{
	/* Determines if interactive or non-interactive*/
	if (isatty(STDIN_FILENO == 1))
	{
		interactive_mode();
	}
	else
	{
		noninteractive_mode();
	}
	return (0);
}
