#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#define max_len_cmd 1024
#define PROMPT "baydre_jay6ks$ "

extern char **environ;

void prompt_display(void);
char *cmd_read(void);
char **tokenize(char *command);
void execute_command(char **args);
void write_error_message(const char *command);

#endif
