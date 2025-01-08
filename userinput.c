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

char *user_input()
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	ssize_t result = 0;
	int i = 0;

	printf("#cisfun$ ");
	fflush(stdout);

	result = getline(&buffer, &bufferSize, stdin);
	if (result == -1)
	{
		printf("hello\n");
		if (buffer != NULL)
		{
			free(buffer);
		}

		exit(EXIT_FAILURE);
	}

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
