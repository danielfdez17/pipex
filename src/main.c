#include "../inc/headers/pipex.h"

/**
 * 
 */
t_pipex	*check_files(char *infile, char *outfile, int *fd_read, int *fd_write)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error();
	*fd_read = open_read_file(infile);
	if (*fd_read == -1)
		error();
	*fd_write = open_write_file(outfile);
	if (*fd_write == -1)
		error();
	return (pipex);
}

/**
 * 
 */
void	fork_loop(t_pipex **pipex, int *fd_read)
{
	if (pipe((*pipex)->fds) == -1)
		error();
	(*pipex)->pid1 = fork();
	if ((*pipex)->pid1 < 0)
		error();
	if ((*pipex)->pid1 == 0)
		run_i_child(*pipex, *fd_read);
	close(*fd_read);
	*fd_read = (*pipex)->fds[0];
	close((*pipex)->fds[1]);
}

void	write_file(t_pipex **pipex, int *fd_write)
{
	if (pipe((*pipex)->fds) == -1)
		error();
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error();
	if ((*pipex)->pid2 == 0)
		run_last_child(*pipex, *fd_write);
	close_fds((*pipex)->fds);
	close(*fd_write);
}

/**
 * 
 */
int main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		fd_read;
	int		fd_write;
	int		cmds;
	int		i;

	if (ac != 5)
		error();
	pipex = check_files(av[1], av[ac - 1], &fd_read, &fd_write);
	cmds = ac - 3;
	i = 0;
	pipex->envp = envp;
	while (cmds-- != 1)
	{
		pipex->cmd1 = av[i + 2];
		fork_loop(&pipex, &fd_read);
		++i;
	}
	pipex->cmd2 = av[i + 2];
	write_file(&pipex, &fd_write);
	// run_child(pipex, fd_read, fd_write, av[i + 2]);
	cmds = ac - 3;
	close_fds(pipex->fds);
	while (cmds--)
		wait(NULL);
	free(pipex);
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
