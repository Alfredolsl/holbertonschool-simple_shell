#include "shell.h"

/**
 * main - main code
 * @ac: arg counter
 * @argv: arg vector
 *
 * Return: 0 if successful, otherwise -1
 */

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			printf("Exiting shell...\n");
			free(lineptr);
			return (-1);
		}

		printf("%s\n", lineptr);
	}

	free(lineptr);

	return (0);
}
