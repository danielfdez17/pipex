/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 16:27:30 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * Main function that creates two child processes
 * to execute the commands received in @param av
 */
int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid1;
	// pid_t	pid2;
	int		status;

	if (ac != 5)
		error();
	if (pipe(fds) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
		run_first_cmd(av, fds, envp);
	// pid2 = fork();
	// if (pid2 < 0)
	// 	error();
	// if (pid2 == 0)
	run_last_cmd(av, fds, envp);
	close_fds(fds);
	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	// waitpid(pid2, NULL, 0);
	return (0);
}
