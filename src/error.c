#include "../inc/headers/pipex.h"

void	error(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
