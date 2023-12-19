#include "shell.h"

/**
 * main - main code
 * @ac: arg counter
 * @argv: arg vector
 *
 * Return: 0 if successful, otherwise 1
 */

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	//while (1)
	//{
	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);
	free(lineptr);
	//}

	return (0);
}
