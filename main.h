#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *user_input();
void exec_command(char *input, char *argv[]);
char **split_command(char *input);
char *find_executable(char *command);

#endif