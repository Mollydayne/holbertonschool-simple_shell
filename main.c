#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	char *input;

	while (1)
	{
		input = user_input();
		if (access(input, F_OK) == 0)
		{
			printf("Executable\n");
		}

		free(input);
	}

	return (0);
}
