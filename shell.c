#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024

extern char **environ;

char *find_command_path(char *command);

int main(void)
{
    char *line = NULL, *command, *argv[10];
    char *cmd_path;
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

        line[strcspn(line, "\n")] = 0;

        i = 0;

        command = strtok(line, " ");
        while (command != NULL && i < 10)
        {
            argv[i++] = command;
            command = strtok(NULL, " ");
        }
        argv[i] = NULL;

        cmd_path = find_command_path(argv[0]);
        if (cmd_path == NULL)
        {
            fprintf(stderr, "%s: Command not found\n", argv[0]);
            continue;
        }

        pid = fork();
        if (pid == -1)
        {
            perror("fork failed");
            free(line);
            return (1);
        }

        if (pid == 0)
        {
            if (execve(cmd_path, argv, environ) == -1)
            {
                perror("Error executing command");
                free(line);
                free(cmd_path);
                exit(1);
            }
        }
        else
        {
            wait(&status);
        }

        free(cmd_path);
    }

    free(line);
    return (0);
}

char *find_command_path(char *command)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char full_path[MAX_CMD_LEN];

    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}
