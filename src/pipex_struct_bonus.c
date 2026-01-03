/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Initializes the t_data structure
 */
bool	init_pipex(int ac, char **av, t_data *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		perror(av[1]);
		pipex->infile = open("/dev/null", O_RDONLY);
	}
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		return (error());
	init_pipe_ends(pipex->pipe_prev);
	pipex->i = 2;
	return (true);
}
