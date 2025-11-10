/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 09:58:59 by danfern3         ###   ########.fr       */
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
void	fork_loop(t_pipex **pipex, t_bool first, t_bool last)
{
	(void)first; 
	(void)last;
	(*pipex)->pid1 = fork();
	if ((*pipex)->pid1 < 0)
		error();
	if ((*pipex)->pid1 == 0)
	{
		if (first)
			ft_dup2((*pipex)->fds[0], (*pipex)->fd_read);
			//  ft_printf("reading from fd_read: %d\n", (*pipex)->fd_read);
		else
			ft_dup2((*pipex)->fds[0], STDIN_FILENO);
		ft_dup2((*pipex)->fds[1], STDOUT_FILENO);
		// (*pipex)->cmd1 = ft_strjoin((*pipex)->cmd1, get_next_line())
		// close((*pipex)->fd_read);
		// // close((*pipex)->fd_write);
		run_command((*pipex)->cmd1, (*pipex)->envp);
		close_fds((*pipex)->fds);
	}
	(*pipex)->pid2 = fork();
	if ((*pipex)->pid2 < 0)
		error();
	if ((*pipex)->pid2 == 0)
	{
		ft_dup2((*pipex)->fds[0], STDIN_FILENO);
		if (last)
			ft_printf("writing in fd_write: %d\n", (*pipex)->fd_write);
			// ft_dup2((*pipex)->fds[1], (*pipex)->fd_write);
		// else
		// 	ft_dup2((*pipex)->fds[1], STDOUT_FILENO);
		// // close((*pipex)->fd_read);
		// close((*pipex)->fd_write);
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
	t_bool	first;
	t_bool	last;
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
		first = (i == 0);
		last = (cmds == ac - 4);
		// ft_printf("i: %d, first: %d, last: %d, cmds:%d\n", i, first, last, cmds);
		fork_loop(&pipex, first, last);
		// pipex->pid1 = fork();
		// if (pipex->pid1 < 0)
		// 	error();
		// if (pipex->pid1 == 0)
		// {
		// 	ft_dup2(pipex->fds[1], STDOUT_FILENO);
		// 	close_fds(pipex->fds);
		// 	run_command(pipex->cmd1, pipex->envp);
		// }
		// pipex->pid2 = fork();
		// if (pipex->pid2 < 0)
		// 	error();
		// if (pipex->pid2 == 0)
		// {
		// 	ft_dup2(pipex->fds[0], STDIN_FILENO);
		// 	close_fds(pipex->fds);
		// 	run_command(pipex->cmd2, pipex->envp);
		// }
		close_fds(pipex->fds);
		++i;
	}
	// pipex->cmd2 = av[i + 2];
	// write_file(&pipex, &fd_write, &fd_read);
	// cmds = ac - 3;
	close(pipex->fd_read);
	close(pipex->fd_write);
	close_fds(pipex->fds);
	// while (cmds--)
	// 	wait(NULL);
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
