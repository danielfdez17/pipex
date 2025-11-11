/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:09 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:36:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"


char	*get_path(char *cmd, char *envp[])
{
	char	**split_path;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	split_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_split(split_path);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(split_path);
	return (NULL);
}

void	run_command(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(argv[0], '.'))
	{
		free_split(argv);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		exit(errno);
	}
	if (ft_strchr(argv[0], '/'))
	{
		path = ft_strdup(argv[0]);
		if (execve(path, argv, envp) < 0)
		{
			free_split(argv);
			free(path);
			error();
		}
	}
	path = get_path(argv[0], envp);
	if (!path)
	{
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		free(path);
		free_split(argv);
		exit(errno);
	}
	if (execve(path, argv, envp) < 0)
	{
		free_split(argv);
		error();
	}
}