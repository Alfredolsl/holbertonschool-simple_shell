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
int forking(char **args);
char **splitline(char *line);
int exec_args(char **args);
char *readstream(void);

/* builtin */
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);

#endif
