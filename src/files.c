#include "../inc/headers/pipex.h"

/**
 * It closes both sides of the pipe
 */
void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

/**
 * Opens @param filename in read mode
 */
int	open_read_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

/**
 * Opens @param filename in write mode
 */
int	open_write_file(char *filename)
{
	int	fd;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		error();
}