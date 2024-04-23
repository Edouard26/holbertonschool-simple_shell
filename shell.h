#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 20

int command_exists(char *command);
void print_environment();
void execute_command(char **args);
char *_getenv(char **env, const char *name);
extern char **environ;
