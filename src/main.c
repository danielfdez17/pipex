#include "../inc/headers/pipex.h"

/**
 * 
 */
// t_pipex	*check_files(char *fd_read, char *fd_write, int *fd_read, int *fd_write)
// {
// 	t_pipex	*pipex;

// 	pipex = malloc(sizeof(t_pipex));
// 	if (!pipex)
// 		error();
// 	*fd_read = open_read_file(fd_read);
// 	if (*fd_read == -1)
// 		error();
// 	*fd_write = open_write_file(fd_write);
// 	if (*fd_write == -1)
// 		error();
// 	return (pipex);
// }

// /**
//  * 
//  */
// void	fork_loop(t_pipex **pipex, int *fd_read)
// {
// 	if (pipe((*pipex)->fds) == -1)
// 		error();
// 	(*pipex)->pid1 = fork();
// 	if ((*pipex)->pid1 < 0)
// 		error();
// 	if ((*pipex)->pid1 == 0)
// 		run_i_child(*pipex, *fd_read);
// 	close(*fd_read);
// 	*fd_read = (*pipex)->fds[0];
// 	close((*pipex)->fds[1]);
// 	close((*pipex)->fds[0]);
// }

// /**
//  * 
//  */
// void	write_file(t_pipex **pipex, int *fd_write, int *fd_read)
// {
// 	if (pipe((*pipex)->fds) == -1)
// 		error();
// 	(*pipex)->pid2 = fork();
// 	if ((*pipex)->pid2 < 0)
// 		error();
// 	if ((*pipex)->pid2 == 0)
// 		run_last_child(*pipex, *fd_write);
// 	close_fds((*pipex)->fds);
// 	close(*fd_write);
// 	close(*fd_read);
// }

// /**
//  * 
//  */
// int main(int ac, char **av, char **envp)
// {
// 	t_pipex	*pipex;
// 	int		fd_read;
// 	int		fd_write;
// 	int		cmds;
// 	int		i;

// 	if (ac != 5)
// 		error();
// 	pipex = check_files(av[1], av[ac - 1], &fd_read, &fd_write);
// 	cmds = ac - 3;
// 	i = 0;
// 	pipex->envp = envp;
// 	while (cmds-- != 1)
// 	{
// 		pipex->cmd1 = av[i + 2];
// 		fork_loop(&pipex, &fd_read);
// 		++i;
// 	}
// 	pipex->cmd2 = av[i + 2];
// 	write_file(&pipex, &fd_write, &fd_read);
// 	cmds = ac - 3;
// 	close(fd_read);
// 	close(fd_write);
// 	while (cmds--)
// 		wait(NULL);
// 	free(pipex);
// 	return (0);
// }

void	fork_loop(int *fd_read, char *envp[], t_pipex **pipex);
t_pipex	*init_prog(int *fd_read, int *fd_write, char *argv[], int argc);
void	write_file(t_pipex **pipex, int *fd_write, char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int		n_cmds;
	t_pipex	*pipex;
	int		fd_read;
	int		fd_write;
	int		i;

	if (argc < 5)
		error();
	pipex = init_prog(&fd_read, &fd_write, argv, argc);
	i = -1;
	n_cmds = argc - 3;
	while (n_cmds-- != 1)
	{
		pipex->cmd1 = argv[2 + ++i];
		fork_loop(&fd_read, envp, &pipex);
	}
	pipex->cmd2 = argv[2 + ++i];
	write_file(&pipex, &fd_write, envp);
	n_cmds = argc - 3;
	while (n_cmds-- != 0)
		wait(NULL);
	free(pipex);
	return (0);
}

t_pipex	*init_prog(int *fd_read, int *fd_write, char *argv[], int argc)
{
	t_pipex	*tmp;

	tmp = malloc(sizeof(t_pipex));
	if (tmp == NULL)
		error();
	*fd_read = open(argv[1], O_RDONLY);
	if (*fd_read < 0)
		error();
	*fd_write = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (*fd_write < 0)
		error();
	return (tmp);
}

void	fork_loop(int *fd_read, char *envp[], t_pipex **pipex)
{
	if (pipe((*pipex)->fds) < 0)
		error();
	(*pipex)->pid1 = fork();
	if ((*pipex)->pid1 < 0)
		error();
	if ((*pipex)->pid1 == 0)
		run_i_child(*pipex, *fd_read, envp);
	close((*pipex)->fds[1]);
	close(*fd_read);
	*fd_read = (*pipex)->fds[0];
}

void	write_file(t_pipex **pipex, int *fd_write, char *envp[])
{
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error();
	if ((*pipex)->pid2 == 0)
		run_last_child(*pipex, *fd_write, envp);
	close((*pipex)->fds[0]);
	close((*pipex)->fds[1]);
	close(*fd_write);
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
