#include "shell.h"

void execute_command(char *args[]) 
{
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
