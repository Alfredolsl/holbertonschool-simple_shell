#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define TOKEN_DELIMITER " \t\r\n\a\""
extern char **environ;

void interactive_mode(void);
void noninteractive_mode(void);
char *readline(void);
char **splitline(char *line);

#endif
