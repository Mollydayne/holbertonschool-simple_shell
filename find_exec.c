#include "main.h"

char *find_executable(char *command)
{
    char *path = getenv("PATH");
    char *full_path = NULL;
    char *token = NULL;
    size_t len = 0;

    if (path == NULL || strchr(command, '/') != NULL)
        return (strdup(command));

    token = strtok(path, ":");
    while (token != NULL)
    {
        len = strlen(token) + strlen(command) + 2;
        full_path = malloc(len);
        if (!full_path)
        {
            perror("malloc");
            return (NULL);
        }
        sprintf(full_path, "%s/%s", token, command);

        if (access(full_path, X_OK) == 0)
            return (full_path);

        free(full_path);
        token = strtok(NULL, ":");
    }
    return (NULL);
}