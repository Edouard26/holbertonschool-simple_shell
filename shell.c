#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {

	char command[MAX_COMMAND_LENGTH];
	pid_t pid;
	while (1) {
		printf("#cisfun$ ");
		fflush(stdout);
		if (fgets(command, sizeof(command), stdin) == NULL) {
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = 0;

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
