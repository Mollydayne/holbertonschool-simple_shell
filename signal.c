#include "main.h"

/**
 * sigint - Signal handler for SIGINT
 * @sig: Signal number
 *
 * Description: This function handles the SIGINT signal (Ctrl+C)
 * and displays a new prompt without exiting the shell.
 */
void sigint(int sig)
{
	(void)sig;
	printf("\n$ ");
	fflush(stdout);
}
