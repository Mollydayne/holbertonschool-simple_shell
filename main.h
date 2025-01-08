#ifndef MAIN_H
#define MAIN_H

/*---LIBRARIES---*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

/*---PROTOTYPES---*/

char *user_input();
void signal_intercepter(int sig);

#endif
