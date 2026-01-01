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

static char	**ft_realloc(char **av, char *line, int size)
{
	char	**new_av;
	int		i;

	new_av = malloc(sizeof(char *) * (size + 2));
	if (!new_av)
		return (NULL);
	i = -1;
	while (av && av[++i])
		new_av[i] = av[i];
	if (av)
		free(av);
	if (line)
		new_av[size] = ft_strdup(line);
	new_av[size + 1] = NULL;
	return (new_av);
}

void	ft_readline(char *limiter)
{
	char	*line;
	char	*tmp;
	char	**argv;
	int		size;

	size = 0;
	argv = NULL;
	tmp = limiter;
	limiter = ft_strjoin(limiter, "\n");
	ft_putstr_fd("> ", STDOUT_FILENO);
	line = get_next_line(STDIN_FILENO, 0);
	argv = ft_realloc(argv, line, size++);
	while (line)
	{
		if (ft_equals(line, limiter))
			break ;
		argv = ft_realloc(argv, line, size++);
		free(line);
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO, 0);
	}
	free(limiter);
	limiter = tmp;
	free(line);
	free_split(argv);
	get_next_line(STDIN_FILENO, 1);
}
