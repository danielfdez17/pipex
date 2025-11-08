#include "../inc/headers/pipex.h"

int	open_read_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

int	open_write_file(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY);
	return (fd);
}
