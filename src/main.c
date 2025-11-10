/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:29:16 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * Checks if the @param infile file exists.
 * If @param outfile file does not exist, 
 * it is created.
 */
t_pipex	*check_files(char *infile, char *outfile)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error(pipex);
	pipex->fd_read = open_read_file(infile);
	if (pipex->fd_read == -1)
		error(pipex);
	pipex->fd_write = open_write_file(outfile);
	if (pipex->fd_write == -1)
		error(pipex);
	return (pipex);
}

/**
 * Loop to process every two command
 */
void	fork_loop(t_pipex **pipex, int fd_read, int fd_write)
{
	(*pipex)->pid1 = fork();
	if ((*pipex)->pid1 < 0)
		error(*pipex);
	if ((*pipex)->pid1 == 0)
	{
		ft_dup2(*pipex, fd_read, STDIN_FILENO);
		ft_dup2(*pipex, (*pipex)->fds[1], STDOUT_FILENO);
		run_command(*pipex, (*pipex)->cmd1, (*pipex)->envp);
		close_fds(*pipex);
	}
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error(*pipex);
	if ((*pipex)->pid2 == 0)
	{
		ft_dup2(*pipex, (*pipex)->fds[0], STDIN_FILENO);
		ft_dup2(*pipex, fd_write, STDOUT_FILENO);
		close_fds(*pipex);
		run_command(*pipex, (*pipex)->cmd2, (*pipex)->envp);
	}
	close_fds(*pipex);
	waitpid((*pipex)->pid1, NULL, 0);
	waitpid((*pipex)->pid2, NULL, 0);
}

/**
 * Last process execution
 */
void	write_file(t_pipex **pipex, int *fd_write, int *fd_read)
{
	if (pipe((*pipex)->fds) == -1)
		error(*pipex);
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error(*pipex);
	if ((*pipex)->pid2 == 0)
		run_last_child(*pipex, *fd_write);
	close_fds(*pipex);
	close(*fd_write);
	close(*fd_read);
}

/**
 * Auxiliary function to reduce number of lines of function main
 */
static void	init_fds(t_pipex *pipex, char **av, int i, int *fd_read_write)
{
	pipex->cmd1 = av[i + 2];
	pipex->cmd2 = av[i + 3];
	fd_read_write[0] = pipex->fds[0];
	fd_read_write[1] = pipex->fds[1];
}

/**
 * Main function that initializes a t_pipex with @param av and @param envp
 * and starts the pipe simulation.
 */
int main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		fd_read_write[2];
	int		i;

	if (ac != 5)
		error(NULL);
	pipex = check_files(av[1], av[ac - 1]);
	i = 0;
	pipex->envp = envp;
	while (i < ac - 4)
	{
		if (pipe(pipex->fds) == -1)
			error(pipex);
		init_fds(pipex, av, i, fd_read_write);
		if (i == 0)
			fd_read_write[0] = pipex->fd_read;
		if (i == ac - 5)
			fd_read_write[1] = pipex->fd_write;
		// ft_printf("i: %d, first: %d, last: %d, cmds:%d\n", i, i == 0, i == cmds - 2, cmds);
		fork_loop(&pipex, fd_read_write[0], fd_read_write[1]);
		close_fds(pipex);
		++i;
	}
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
