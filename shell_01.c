#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int command_exists(const char *command) 
{
	
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	while (dir != NULL) {
		char command_path[MAX_COMMAND_LENGTH];
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0) {
			free(path_copy);
			return (1);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}

int main() {
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;

	while (1) {
		printf(":) ");
		fflush(stdout);
		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = 0;

		if (!command_exists(command)) {
			printf("%s: command not found\n", command);
			continue;
		}
		pid = fork();

		if (pid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		} else if (pid == 0) {
			if (execlp(command, command, (char *)NULL) == -1) {
				perror(command);
				exit(EXIT_FAILURE);
			}
		} else {
			int status;
			waitpid(pid, &status, 0);
		}
	}

	return (0);
}