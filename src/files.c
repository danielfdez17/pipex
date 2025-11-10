/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:34 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:37:56 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * It closes both sides of the pipe
 */
void	close_fds(t_pipex *pipex)
{
	close(pipex->fds[0]);
	close(pipex->fds[1]);
	close(pipex->fd_read);
	close(pipex->fd_write);
}

/**
 * Opens @param filename in read mode
 */
int	open_read_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	return (fd);
}

/**
 * Opens @param filename in write, create or truncate mode
 */
int	open_write_file(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

/**
 * Calls error if dup2 fails
 */
void	ft_dup2(t_pipex *pipex, int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		error(pipex);
}
