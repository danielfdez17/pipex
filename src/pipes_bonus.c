/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Initializes the pipe @param fds ends to -1
 */
void	init_pipe_ends(int fds[2])
{
	fds[0] = -1;
	fds[1] = -1;
}

/**
 * Closes both files descriptors @param infile and @param outfile
 */
void	close_files(int infile, int outfile)
{
	close(infile);
	close(outfile);
}

/**
 * Updates the @param prev pipe ends with the @param curr pipe ends
 */
void	update_pipe_ends(int prev[2], int curr[2])
{
	prev[0] = curr[0];
	prev[1] = curr[1];
}
