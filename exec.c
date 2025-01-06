#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - execve example²²²
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}