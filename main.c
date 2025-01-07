#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	size_t size = 0;
	int i;
	char *input, *executable, *cwd;
    char **args;
    (void)argc;
    (void)argv;
	

    while (1)
    {
       input = user_input();

        args = split_command(input);
        if (args == NULL || args[0] == NULL)
        {
            free(input);
            free(args);
            continue;
        }

        executable = find_executable(args[0]);
        if (executable == NULL)
        {
           cwd = getcwd(NULL, size);
            if (cwd != NULL)
            {
                 fprintf(stderr, "%s/%s: %s: command not found\n", cwd, argv[0], args[0]);
                free(cwd);
            }
			else
            {
                perror("getcwd");
            }
        }
        else
        {
            exec_command(executable, args);
            free(executable);
        }

        for (i = 0; args[i] != NULL; i++)
            free(args[i]);
        free(args);
        free(input);
    }

    return (0);
}