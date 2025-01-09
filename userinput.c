#include "main.h"
#include <errno.h>

/**
 * user_input - Reads a line of input from the user
 *
 * Description:
 * This function prompts the user with a "$ " symbol, waits for input
 *
 * Return: A pointer to the dynamically allocated string containing
 * the user's input.
 */

char **user_input()
{
	char *buffer = NULL;
	char **tokens;
	size_t bufferSize = 0;
	ssize_t result = 0;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}

	result = getline(&buffer, &bufferSize, stdin);
	if (result == -1)
	{
		if (buffer != NULL)
		{
			free(buffer);
		}

		exit(EXIT_FAILURE);
	}

	if (buffer[result - 1] == '\n')
	{
		buffer[result - 1] = '\0';
	}

	tokens = split_line(buffer);

	return (tokens);
}
