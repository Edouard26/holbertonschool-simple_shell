#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *args[]) {
	pid_t pid;
	char *path;
	char *dir;
	int status;


	path = _getenv(environ, "PATH");
	if (path == NULL) {
		perror("getenv");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {

		char *path_copy = strdup(path);
		dir = strtok(path_copy, ":");
		while (dir != NULL) {

			char command_path[MAX_COMMAND_LENGTH];
			strcpy(command_path, dir);
			strcat(command_path, "/");
			strcat(command_path, args[0]);

			if (access(command_path, X_OK) == 0) {

				execve(command_path, args, NULL);
				perror(args[0]);
				_exit(EXIT_FAILURE);
			}
			dir = strtok(NULL, ":");
		}
		fprintf(stderr, "%s: command not found\n", args[0]);
		free(path_copy);
		exit(EXIT_FAILURE);
	} else {
		waitpid(pid, &status, 0);
	}
	free(path);
}
