#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(const char *input, int *word_count) 
{
	int count = 0;
	const char *ptr = input;
	while (*ptr != '\0') {

		while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
			ptr++;

		if (*ptr != '\0') {
			count++;


			while (*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != '\0')
				ptr++;
		}
	}

	char **words = (char **)malloc(count * sizeof(char *));
	if (words == NULL) {
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	char *copy = strdup(input);
	if (copy == NULL) {
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(copy, " \t\n");
	for (int i = 0; i < count; i++) {
		words[i] = strdup(token);
		if (words[i] == NULL) {
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}
	free(copy);

	*word_count = count;

	return (words);
}

int main(void) {
	const char *input = "Write a function that splits a string";
	int word_count;
	char **words = split_string(input, &word_count);

	printf("Number of words: %d\n", word_count);
	printf("Words:\n");
	for (int i = 0; i < word_count; i++) {
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);

	return (0);
}
