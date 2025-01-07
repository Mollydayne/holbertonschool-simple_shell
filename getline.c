#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    ssize_t chars_read = 0;
    char *line = NULL, *token, *sep = " \n";
    size_t buff_len = 0;
    char **array = NULL;
    int i = 0;

    printf("$ ");
    chars_read = getline(&line, &buff_len, stdin);
    if (chars_read == -1)
    {
        free(line);
        return (1);
    }

    array = malloc(sizeof(char *) * chars_read);
    if (array == NULL)
    {
        free(line);
        return (1);
    }

    token = strtok(line, sep);
    while (token != NULL)
    {
        int len = strlen(token);
        array[i] = malloc(len + 1);
        if (array[i] == NULL)
        {

            for (int j = 0; j < i; j++)
                free(array[j]);
            free(array);
            free(line);
            return (1);
        }
        strcpy(array[i], token);
        token = strtok(NULL, sep);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Token[%d]: %s\n", j, array[j]);
        free(array[j]);
    }

    free(array);
    free(line);
    return (0);
}