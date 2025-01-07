#include "main.h"

char **split_command(char *input)
{
    char **args = NULL;
    char *token = NULL;
    size_t count = 0;

    args = malloc(sizeof(char *) * 64);
    if (!args)
    {
        perror("malloc");
        return (NULL);
    }

    token = strtok(input, " ");
    while (token != NULL)
    {
        args[count++] = strdup(token);
        token = strtok(NULL, " ");
    }
    args[count] = NULL;

    return (args);
    }