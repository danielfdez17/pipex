#include "../inc/headers/pipex.h"

/**
 * Frees the memory used by @param split
 */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
	split = NULL;
}
