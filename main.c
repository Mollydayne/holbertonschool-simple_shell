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

	while (1)
	{
		input = user_input();
		printf("%s\n", input);
		if (access(input, F_OK) == 0)
		{
			printf("Executable\n");
		}

		free(input);
	}

	return (0);
}
