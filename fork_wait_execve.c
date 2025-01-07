#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    for (int i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error during fork");
            return (1);
        }

        if (child_pid == 0)
        {
            printf("Child %d executing ls -l /tmp\n", i + 1);
            execve(argv[0], argv, NULL);
            perror("Error during execve");
            return (1);
        }
        else
        {
            wait(&status);
        }
    }

    printf("All child processes have finished.\n");
    return 0;
}
