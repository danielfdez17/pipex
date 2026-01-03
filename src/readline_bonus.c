/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:25:36 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_readline(char *limiter)
{
	char	*line;
	int		fd;

	fd = open(".here_doc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		error();
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO, 0);
	while (line)
	{
		if (ft_equals(line, limiter))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		ft_putstr_fd("> ", STDOUT_FILENO);
		free(line);
		line = get_next_line(STDIN_FILENO, 0);
	}
	get_next_line(STDIN_FILENO, 1);
	close(fd);
}
