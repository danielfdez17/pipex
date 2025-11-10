/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 11:41:17 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * 
 */
t_pipex	*check_files(char *infile, char *outfile)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error();
	pipex->fd_read = open_read_file(infile);
	if (pipex->fd_read == -1)
		error();
	pipex->fd_write = open_write_file(outfile);
	if (pipex->fd_write == -1)
		error();
	return (pipex);
}

/**
 * Loop to process every command
 */
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
// 	fd_read = &(*pipex)->fds[0];
// 	close((*pipex)->fds[1]);
// 	close((*pipex)->fds[0]);
// }

// ! fds[0] -> write, fds[1] -> read
// * le puedo pasar el archivo de lectura y de escritura como parámetro, y me ahorro el firt y last
void	fork_loop(t_pipex **pipex, int fd_read, int fd_write)
{
	(*pipex)->pid1 = fork();
	if ((*pipex)->pid1 < 0)
		error();
	if ((*pipex)->pid1 == 0)
	{
		ft_dup2(fd_read, STDIN_FILENO);
		ft_dup2((*pipex)->fds[1], STDOUT_FILENO);
		run_command((*pipex)->cmd1, (*pipex)->envp);
		close_fds((*pipex)->fds);
	}
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error();
	if ((*pipex)->pid2 == 0)
	{
		ft_dup2((*pipex)->fds[0], STDIN_FILENO);
		ft_dup2(fd_write, STDOUT_FILENO);
		close_fds((*pipex)->fds);
		run_command((*pipex)->cmd2, (*pipex)->envp);
	}
	close_fds((*pipex)->fds);
	close((*pipex)->fd_read);
	close((*pipex)->fd_write);
	waitpid((*pipex)->pid1, NULL, 0);
	waitpid((*pipex)->pid2, NULL, 0);
}

/**
 * Last process execution
 */
void	write_file(t_pipex **pipex, int *fd_write, int *fd_read)
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
	close(*fd_read);
}

/**
 * Main function
 */
int main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		cmds;
	int		fd_read;
	int		fd_write;
	int		i;

	if (ac < 5)
		error();
	pipex = check_files(av[1], av[ac - 1]);
	cmds = ac - 3;
	i = 0;
	pipex->envp = envp;
	while (cmds-- != 1)
	{
		pipex->cmd1 = av[i + 2];
		pipex->cmd2 = av[i + 3];
		if (pipe(pipex->fds) == -1)
			error();
		fd_read = pipex->fds[0];
		fd_write = pipex->fds[1];
		if (i == 0)
			fd_read = pipex->fd_read;
		if (cmds == ac - 4)
			fd_write = pipex->fd_write;
		ft_printf("i: %d, first: %d, last: %d, cmds:%d\n", i, i == 0, cmds == ac - 4, cmds);
		// fork_loop(&pipex, fd_read, fd_write);
		close_fds(pipex->fds);
		++i;
	}
	close(pipex->fd_read);
	close(pipex->fd_write);
	close_fds(pipex->fds);
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
