#include "shell.h"

/**
 * readline - reads the line from stdin and
 * copies it into a buffer
 */

char *readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading line from standard input");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
