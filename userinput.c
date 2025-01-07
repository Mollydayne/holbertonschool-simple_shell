#include "main.h"
#include <errno.h>

/**
 * user_input - Reads a line of input from the user
 *
 * Description:
 * This function prompts the user with a "$ " symbol and reads a line of
 * text from standard input. The input is stored in a dynamically allocated
 * buffer. If the input contains a newline character, it is replaced with
 * a null terminator. In case of an error (e.g., EOF), the function frees
 * the allocated memory and exits the program.
 *
 * Return: A pointer to the dynamically allocated string containing
 * the user's input.
 */

char *user_input()
{
	char *buffer = NULL;
	size_t bufferSize = 0;
	int result = 0;
	int i = 0;

	printf("$ ");
	fflush(stdout);

	result = getline(&buffer, &bufferSize, stdin);
	if (result == -1)
	{
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
