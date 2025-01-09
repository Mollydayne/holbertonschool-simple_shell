#include "main.h"

char **split_line(char *line)
{
    char **args = malloc(64 * sizeof(char *));
    char *token;
    int i = 0;

    if (!args)
   {
        perror("Erreur d'allocation");
        exit(EXIT_FAILURE);
   }

    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return (args);
}