/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * Runs the first command reading the content of the infile file
 */
void	run_first_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		close_fds(fds);
		return ;
	}
	// close(fds[0]);
	ft_dup2(fd, STDIN_FILENO);
	ft_dup2(fds[1], STDOUT_FILENO);
	close_fds(fds);
	run_command(av[2], envp);
}

/**
 * Runs the last command reading the output of the first cmd
 * and writing its output in the outfile file
 */
void	run_last_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		error();
	// close(fds[1]);
	ft_dup2(fds[0], STDIN_FILENO);
	ft_dup2(fd, STDOUT_FILENO);
	close_fds(fds);
	run_command(av[3], envp);
}

/**
 * Main function that creates two child processes
 * to execute the commands received in @param av
 */
int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac != 5)
		error();
	if (pipe(fds) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
		run_first_cmd(av, fds, envp);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		run_last_cmd(av, fds, envp);
	close_fds(fds);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
