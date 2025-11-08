#include "../inc/headers/pipex.h"

/**
 * It closes both sides of the pipe
 */
void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}