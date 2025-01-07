#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

int main(void)
{
    char *line = NULL, *command;
    size_t len = 0;
    ssize_t chars_read;
    pid_t pid;
    int status;

    while (1)
    {

        printf("#cisfun$ ");
        chars_read = getline(&line, &len, stdin);
        if (chars_read == -1)
        {
            free(line);
            return (1);
        }

        line[strcspn(line, "\n")] = 0;

        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            free(line);
            return (1);
        }
        
        if (pid == 0)
        {

            command = line;
            if (execve(command, &command, NULL) == -1)
            {
                perror("Error executing command");
                free(line);
                exit(1);
            }
        }
        else
        {
            wait(&status);
        }
    }

    free(line);
    return (0);
}