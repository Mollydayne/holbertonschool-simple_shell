#include "main.h"
#include <errno.h>

char* user_input()
{
	char* buffer = NULL;
	size_t bufferSize = 0;
	int result = 0;

	printf("$ ");
	fflush(stdout);

	result = getline(&buffer, &bufferSize, stdin);
	if (result == -1)
	{
		if(buffer != NULL)
		{
			free(buffer);
		}

		exit(EXIT_FAILURE);
	}

	return (buffer);
}
