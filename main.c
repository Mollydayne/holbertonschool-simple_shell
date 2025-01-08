#include "main.h"
#include <sys/wait.h>

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
	pid_t pid;
	int pidStatus;
	(void)argc;
	(void)argv;

	while (1)
	{
		input = user_input();
		if (access(input, X_OK) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				if (execve(input, argv, __environ) == -1)
				{
					perror("Failed to execute command");
					free(input);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(pid, &pidStatus, 0);
			}
		}
		else
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
		free(input);
	}

	return (0);
}
