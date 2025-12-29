/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Initializes the t_pipex structure
 */
static t_pipex	init_pipex(int ac, char **av)
{
	t_pipex	pipex;

	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		perror(av[1]);
		pipex.infile = open("/dev/null", O_RDONLY);
	}
	pipex.outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		error();
	init_pipe_ends(pipex.pipe_prev);
	pipex.i = 2;
	return (pipex);
}

/**
 * Function executed by the child process
 */
static void	child_process(int ac, char **av, char **envp, t_pipex *pipex)
{
	if (pipex->pipe_prev[0] != -1)
		ft_dup2(pipex->pipe_prev[0], STDIN_FILENO);
	else
		ft_dup2(pipex->infile, STDIN_FILENO);
	if (pipex->i != ac - 2)
		ft_dup2(pipex->pipe_curr[1], STDOUT_FILENO);
	else
		ft_dup2(pipex->outfile, STDOUT_FILENO);
	close_fds(pipex->pipe_prev);
	if (pipex->i != ac - 2)
		close_fds(pipex->pipe_curr);
	close_files(pipex->infile, pipex->outfile);
	run_command(av[pipex->i], envp);
	exit(1);
}

/**
 * Creates a child process to run the command
 */
static void	create_child(int ac, char **av, char **envp, t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
		error();
	if (pipex->pid == 0)
		child_process(ac, av, envp, pipex);
}

/**
 * Main function that creates a child processes
 * to execute the commands received in @param av
 */
int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac < 5)
		error();
	pipex = init_pipex(ac, av);
	init_pipe_ends(pipex.pipe_prev);
	pipex.i = 2;
	while (pipex.i < ac - 1)
	{
		if (pipex.i != ac - 2)
		{
			if (pipe(pipex.pipe_curr) < 0)
				error();
		}
		create_child(ac, av, envp, &pipex);
		close_fds(pipex.pipe_prev);
		if (pipex.i != ac - 2)
			update_pipe_ends(pipex.pipe_prev, pipex.pipe_curr);
		pipex.i++;
	}
	close_fds(pipex.pipe_prev);
	close_files(pipex.infile, pipex.outfile);
	while (wait(NULL) > 0)
		;
	return (0);
}
