#include <stdio.h>

int main(int argc, char **argv)
{
    int i = 0, j;
    while (argv[i] != NULL)
    i++;
    ;
      for(j = 0; j < argc; j++)
    printf("argv[%d] = %s\n", j, argv[j]);

    return(0);
}