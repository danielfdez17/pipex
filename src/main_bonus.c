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

#include "../inc/headers/pipex_bonus.h"

/**
 * Main function that creates two child processes
 * to execute the commands received in @param av
 */
// int	main(int ac, char **av, char **envp)
// {
// 	// int	fd_read;
// 	// int	fd_write;
// 	int	status;
// 	int	i;
// 	int	fds[2];
// 	pid_t pid1, pid2, pid3;
// 	(void)pid2;

// 	if (ac < 5)
// 		return (0);
// 	if (pipe(fds) == -1)
// 		error();
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		error();
// 	if (pid1 == 0)
// 		run_first_cmd(av, fds, envp);

// 	// ft_dup2(fd_read, STDIN_FILENO);
// 	// ! este bucle lo puede hacer un pid3, como la lectura y escritura
// 	// pid2 = fork();
// 	// if (pid2 < 0)
// 	// 	error();
// 	i = 3;
// 	// if (pid2 == 0)
// 	// {
// 		while (i < ac - 2)
// 			run_i_cmd(av, envp, i++);
// 	// }
// 	pid3 = fork();
// 	if (pid3 < 0)
// 		error();
// 	if (pid3 == 0)
// 		run_last_cmd(ac, av, fds, envp);
// 	// fd_read = open_read_file(av[1]);
// 	// fd_write = open_write_file(av[ac - 1]);
// 	// if (pipe(fds) < 0)
// 	// 	error();
// 	// ft_calloc(sizeof(char *), 10);
// 	// return (0);

// 	// run_command(av[ac - 2], envp);
// 	close_fds(fds);
// 	waitpid(pid1, &status, 0);
// 	// waitpid(pid2, &status, 0);
// 	waitpid(pid3, &status, 0);
// 	if (WIFEXITED(status))
// 		exit(WEXITSTATUS(status));
// 	return (0);
// }

void	init_pipe_ends(int fds[2])
{
	fds[0] = -1;
	fds[1] = -1;
}
void	update_pipe_ends(int prev[2], int curr[2])
{
	prev[0] = curr[0];
	prev[1] = curr[1];
}
void	close_files(int infile, int outfile)
{
	close(infile);
	close(outfile);
}

static t_pipex	*init_pipex(int ac, char **av)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		error();
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror(av[1]);
		pipex->infile = open("/dev/null", O_RDONLY);
	}
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		error();
	init_pipe_ends(pipex->pipe_prev);
	pipex->i = 2;
	return (pipex);
}

int main(int ac, char **av, char **envp)
{
	t_pipex *pipex;

	if (ac < 5)
		error();
	pipex = init_pipex(ac, av);
	while (pipex->i < ac - 1)
	{
		if (pipex->i != ac - 2)
		{
			if (pipe(pipex->pipe_curr) < 0)
				error();
		}
		pipex->pid = fork();
		if (pipex->pid < 0)
			error();
		if (pipex->pid == 0)
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
			exit(EXIT_SUCCESS);
		}
		close_fds(pipex->pipe_prev);
		if (pipex->i != ac - 2)
			update_pipe_ends(pipex->pipe_prev, pipex->pipe_curr);
		pipex->i++;
	}
	close_fds(pipex->pipe_prev);
	close_files(pipex->infile, pipex->outfile);
	while (wait(NULL) > 0)
		;
	return (0);
}
