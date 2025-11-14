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
int	main(int ac, char **av, char **envp)
{
	// int	fd_read;
	// int	fd_write;
	int	i;
	int	fds[2];
	pid_t pid1, pid2;

	if (ac < 5)
		return (0);
	if (pipe(fds) == -1)
		error_bonus();
	pid1 = fork();
	if (pid1 < 0)
		error_bonus();
	if (pid1 == 0)
		run_first_cmd(av, fds, envp);

	// ft_dup2_bonus(fd_read, STDIN_FILENO);
	// ! este bucle lo puede hacer un pid3, como la lectura y escritura
	while (i < ac - 2)
		run_i_cmd_bonus(av, fds, envp, i++);
	// ft_dup2_bonus(fd_write, STDOUT_FILENO);

	pid2 = fork();
	if (pid2 < 0)
		error_bonus();
	if (pid2 == 0)
		run_last_cmd(ac, av, fds, envp);
	// fd_read = open_read_file_bonus(av[1]);
	// fd_write = open_write_file_bonus(av[ac - 1]);
	i = 2;
	// if (pipe(fds) < 0)
	// 	error_bonus();
	// ft_calloc(sizeof(char *), 10);
	// return (0);

	// run_command_bonus(av[ac - 2], envp);
	close_fds_bonus(fds);
	return (0);
}
