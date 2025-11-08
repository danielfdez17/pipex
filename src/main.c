

#include "../inc/headers/pipex.h"

int main(int ac, char **av)
{
	int	fd_read;
	int	fd_write;

	if (ac != 5)
	{
		ft_printf("The program needs exactly 4 arguments\n");
		return (0);
	}
	fd_read = open_read_file(av[1]);
	if (fd_read == -1)
	{
		ft_printf("File '%s' could not have been opened\n", av[1]);
		return (1);
	}
	fd_write = open_write_file(av[ac - 1]);
	if (fd_write == -1)
	{
		ft_printf("File '%s' could not have been opened\n", av[ac - 1]);
		return (1);
	}
	pipex(ac, av, fd_read, fd_write);
	return (0);
}

// * Pipe (|) simulation
// int main(void)
// {
// 	int fds[2];

// 	if (pipe(fds) == -1)
// 		return (1);
// 	int pid1 = fork();
// 	if (pid1 < 0)	
// 		return (2);
// 	if (pid1 == 0)
// 	{
// 		char *av[] = {"ls", "-l", NULL};
// 		// Child process one (ls -l)
// 		dup2(fds[1], STDOUT_FILENO);
// 		close_fds(fds);
// 		if (execve("/usr/bin/ls", av, NULL) == -1)
// 			perror("Could not execute execve");
// 	}
// 	int pid2 = fork();
// 	if (pid2 < 0)
// 		return (4);
// 	if (pid2 == 0)
// 	{
// 		char *av[] = {"wc", "-l", NULL};
// 		// Child process two (wc -l)
// 		dup2(fds[0], STDIN_FILENO);
// 		close_fds(fds);
// 		if (execve("/usr/bin/wc", av, NULL) == -1)
// 			perror("Could not execute execve");
// 	}
// 	close_fds(fds);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }
