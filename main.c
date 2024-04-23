#include "shell.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 20

int main() {
	char *command = NULL;
	size_t command_size = 0;
	char *args[MAX_ARGS];
	int arg_count;
	ssize_t read_bytes;
	char *token;

	if (isatty(STDIN_FILENO)) 
	{
		printf("Interactive mode\n");
	} else 
	{
		printf("Non-interactive mode\n");
	}

	while (1) {
		printf(":) ");
		fflush(stdout);
		read_bytes = getline(&command, &command_size, stdin);
	

		command[read_bytes - 1] = '\0';

		arg_count = 0;
		token = strtok(command, "\t\n ");
		while (token != NULL && arg_count < MAX_ARGS - 1) {
			args[arg_count++] = token;
			token = strtok(NULL, "\t\n ");
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

		if (command_exists(args[0]) == 0 ) {
			printf("%s: command not found\n", args[0]);
			continue;
		}

		execute_command(args);
	}

	free(command);
	return (0);
}
