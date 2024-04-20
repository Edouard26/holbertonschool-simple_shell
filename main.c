#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 20

int command_exists(const char *command);
void print_environment(void);
void execute_command(char *args[]);

int main() {
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
	int arg_count;

	while (1) {
		printf(":) ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		arg_count = 0;
		char *token = strtok(command, " ");
		while (token != NULL && arg_count < MAX_ARGS - 1) {
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (arg_count == 0) {
			continue;
		}

		if (strcmp(args[0], "exit") == 0) {
			printf("Exiting shell...\n");
			break;
		} else if (strcmp(args[0], "env") == 0) {
			print_environment();
			continue;
		}

		if (!command_exists(args[0])) {
			printf("%s: command not found\n", args[0]);
			continue;
		}

		execute_command(args);
	}

	return 0;
}

int command_exists(const char *command) {
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL) {
		char command_path[MAX_COMMAND_LENGTH];
		snprintf(command_path, sizeof(command_path), "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0) {
			free(path_copy);
			return 1;
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return 0;
}

void print_environment(void) {
	extern char **environ;
	char **env = environ;

	while (*env != NULL) {
		printf("%s\n", *env);
		env++;
	}
}

void execute_command(char *args[]) {
	pid_t pid = fork();

	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	} else {
		int status;
		waitpid(pid, &status, 0);
	}
}
