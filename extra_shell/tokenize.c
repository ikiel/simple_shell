#include "shell.h"
/**
 * tokenize - splits a line into tokens
 * @line: line to split
 * @delim: the delimiter
 *
 * Return: array of tokens
 */
char **tokenize(char *line, const char delim)
{
	char  **token = NULL;
	int i = 0, j, w = 0;

	while (line[i] != '\0' && line[i] == delim)
		i++;
	if (!line[i])
		return (NULL);
	i = 0;
	while (line[i])
	{
		j = i;
		if (line[i] != delim)
		{
			token = _realloc(token, sizeof(char *) * w,
					sizeof(char *) * (w + 1));
			token(w) = NULL;
			while (line[j] && line[j] != delim)
			{
				token[w] = _realloc(token[w], (j - i), ((j - i) + 1));
				token[w][j - i] = line[j];
				j++;
			}
			token[w] = _realloc(token[w], (j - i), ((j - i) + 1));
			token[w][j - i] = '\0';
			i += (j - i);
			w++;
		}
		else
			i++;
	}
	token = _realloc(token, sizeof(char *) * w, sizeof(char *) * (w + 1));
	token[w] = NULL;

	return (token);
}
