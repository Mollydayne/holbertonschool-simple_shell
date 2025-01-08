#include "main.h"

/**
 * main - Entry point of the program
 *
 * @argc: The number of arguments passed to the program
 * @argv: The array of arguments passed to the program
 *
 * Description:
 * This program continuously prompts the user for input,
 * checks if the provided input corresponds to an accessible
 * file path, and prints "Executable" if the file exists.
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *input;
	(void)argc;
	(void)argv;

	while (1)
	{
		input = user_input();
		if (input == NULL)
		{
			printf("\n");
			break;
		}

		if (access(input, X_OK) == 0)
		{
			if (execve(input, argv, __environ) == -1)
			{
				perror(input);
			}
		}
		else
		{
			printf("No such file or directory or not executable\n");
		}
		free(input);
	}

	return (0);
}
