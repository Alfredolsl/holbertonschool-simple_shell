#include "shell.h"

int main (ac, **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}