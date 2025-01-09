#include "main.h"

/**
 * split_line - function to split a line
 * and handle token parsing
 *
 *
 * Description:
 * locate space and words
 *
 * Return: Always 0 (Success)
 */

char **split_line(char *line)
{
	char **tokensArray;
	char *token;
	int i = 0;

	if (line == NULL)
		return (NULL);

	tokensArray = malloc((strlen(line) + 1) * sizeof(char *));
	if (tokensArray == NULL)
		return (NULL);

	token = strtok(line, " ");
	while (token)
	{
		tokensArray[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	tokensArray[i] = NULL;
	return (tokensArray);
}
