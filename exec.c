#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * exec_command - Executes a command in a child process
 *
 * @input: The command to execute
 * @argv: The arguments to pass to the command
 *
 * Description:
 * This function is called by the parent process to create a child
 * process, execute the command with `execve()`, and handle the 
 * status of the child process.
 */
void exec_command(char *input, char *argv[])
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("An error occured during the fork");
        free(input);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(input, argv, NULL);

        perror("An error occured during execution");
        free(input);
        exit(EXIT_FAILURE);
    }
    else
    {
  
        wait(&status);

        if (status == 0)
        {
            printf("The process has succeeded ( return code : 0)\n");
        }
        else if ((status & 0xFF) != 0)
        {
            printf("The process has been killed by a signal.\n");
        }
        else
        {
            printf("The process failed with the following error code : %d\n", status >> 8);
        }
    }
}