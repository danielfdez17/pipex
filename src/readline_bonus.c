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

char	**ft_realloc(char **av, char *line, int size, bool free_line)
{
	char	**new_av;
	int		i;

	new_av = malloc(sizeof(char *) * (size + 2));
	if (!new_av)
		return (NULL);
	i = -1;
	while (av && av[++i])
		new_av[i] = av[i];
	if (av && free_line)
		free(av);
	if (line)
		new_av[size] = ft_strdup(line);
	new_av[size + 1] = NULL;
	return (new_av);
}

void	ft_readline(t_here_doc *heredoc)
{
	char	*line;
	char	*tmp;

	tmp = heredoc->limiter;
	heredoc->limiter = ft_strjoin(heredoc->limiter, "\n");
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO, 0);
	while (line)
	{
		if (ft_equals(line, heredoc->limiter))
			break ;
		heredoc->args = ft_realloc(heredoc->args, line, heredoc->size++, true);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO, 0);
	}
	free(heredoc->limiter);
	heredoc->limiter = tmp;
	free(line);
	get_next_line(STDIN_FILENO, 1);
}
