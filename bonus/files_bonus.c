/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:34 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:37:56 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex_bonus.h"

/**
 * Closes both sides of the pipe
 * ! fds[0] = read end
 * ! fds[1] = write end
 */
void	close_fds_bonus(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

/**
 * Opens @param filename in read mode
 */
int	open_read_file_bonus(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0644);
	if (fd < 0)
		error_bonus();
	return (fd);
}

/**
 * Opens @param filename in write, create or truncate mode
 */
int	open_write_file_bonus(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		error_bonus();
	return (fd);
}

/**
 * Calls error if dup2 fails
 */
void	ft_dup2_bonus(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		error_bonus();
}
