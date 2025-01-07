#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

extern char **environ;

int main(void)
{
    char *line = NULL, *command, *argv[10];
    size_t len = 0;
    ssize_t chars_read;
    pid_t pid;
    int status;
    int i;

    while (1)
    {
        printf("#cisfun$ ");
        chars_read = getline(&line, &len, stdin);
        if (chars_read == -1)
        {
            printf("\n");
            free(line);
            return (0);
        }

        if (line[chars_read - 1] == '\n')
        {
            line[chars_read - 1] = '\0';
        }

        i = 0;
        command = strtok(line, " ");
        while (command != NULL && i < 10)
        {
            argv[i++] = command;
            command = strtok(NULL, " ");
        }
        argv[i] = NULL;

        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            free(line);
            return (1);
        }

        if (pid == 0)
        {
            if (execve(argv[0], argv, environ) == -1)
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

        free(line);
    }

    return (0);
}
