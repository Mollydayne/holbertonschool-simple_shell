#include "main.h"

int main() 
{
    char *line = NULL;
    size_t len = 0;
    char **args;
    int i;

    printf("Entrez une commande : ");
    if (getline(&line, &len, stdin) == -1);
    {
        perror("Erreur lors de la lecture de la ligne");
        free(line);
        exit(EXIT_FAILURE);
    }
    args = split_line(line);
    for (i = 0; args[i] != NULL; i++)
    {
        printf("args[%d] = %s\n", i, args[i]);
    }

    free(line);
    free(args);
    return 0;
}
