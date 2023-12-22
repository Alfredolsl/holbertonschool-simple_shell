#include "shell.h"

/**
 * main - main code
 * @ac: arg counter
 * @argv: arg vector
 *
 * Return: 0 if successful, otherwise -1
 */

int main(int ac __attribute__((unused)), char **argv)
{
	char *prompt = "$ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	char *token = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	unsigned int token_count, i;
	int interactive, execute_command;

	while (1)
	{
		token_count = 0;
		interactive = is_interactive();

		if (interactive == 0)
			printf("%s", prompt);
		
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			if (interactive == 0)
				printf("\n");
			free(lineptr);
			return(-1);
		}

		lineptr_copy = malloc(sizeof(char) * (nchars_read + 1));
		if (lineptr_copy == NULL)
		{
			perror("Error: memory could not be allocated");
			free(lineptr);
			return (-1);
		}

		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			token_count++;
			token = strtok(NULL, delim);
		}

		token_count++;
		argv = malloc(sizeof(char *) * token_count);

		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (strlen(token)) + 1);
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}

		argv[i] = NULL;

		execute_command = execmd(argv);
		if (execute_command != 0)
		{
			for (i = 0; i < token_count; i++)
			{
				if (argv[i] != NULL && execute_command == 0)
				{
					printf("%s", argv[i]);
				}
			}
		}

		for (i = 0; i < token_count; i++)
			free(argv[i]);
	}

	free(argv);
	free(lineptr_copy);
	free(lineptr);

	return (0);
}
