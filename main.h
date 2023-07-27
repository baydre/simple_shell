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

void free_tokens(char **tokens);

void prompt_display(void);
char *cmd_read(void);
char **tokenise(char *command);
void execute_command(char *command, char **args);
void write_error_message(const char *command);

int find_file(char *path);
char *witch(char *filename, char *path);

int isExit(char **tokens);
int isEnv(char **tokens);

int _strcmp(char *s1, char *s2);
char *_strcp(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *str);

void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size);

char* _getenv(const char* name);

#endif
