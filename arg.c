#include "main.h"
#include <ctype.h>

/**
 * split_command - Splits a command string into arguments
 *
 * @input: The command string to split
 *
 * Return: A NULL-terminated array of strings containing the arguments,
 *         or NULL if an error occurs.
 */
char **split_command(char *input)
{
    char **args = NULL;
    char *token = NULL;
    size_t count = 0, capacity = 16, i;
    char *start = NULL;

    if (!input)
        return (NULL);

    args = malloc(sizeof(char *) * capacity);
    if (!args)
    {
        perror("malloc");
        return (NULL);
    }

    start = input;
    while (*start)
    {
        while (isspace(*start))
            start++;

        if (*start == '\0')
            break;

        token = start;

        if (*start == '"' || *start == '\'')
        {
            char quote = *start++;
            token = start;
            while (*start && *start != quote)
                start++;
            if (*start)
                *start++ = '\0';
        }
        else
        {
            while (*start && !isspace(*start))
                start++;
        }

        if (*start)
            *start++ = '\0';

        if (count >= capacity - 1)
        {
            capacity *= 2;
            args = realloc(args, sizeof(char *) * capacity);
            if (!args)
            {
                perror("realloc");
                return (NULL);
            }
        }

        args[count++] = strdup(token);
        if (!args[count - 1])
        {
            perror("strdup");
            for (i = 0; i < count - 1; i++)
                free(args[i]);
            free(args);
            return (NULL);
        }
    }

    args[count] = NULL;
    return (args);
}
