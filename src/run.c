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

/**
 * @returns the path stored in @param envp
 */
char	*get_path(char *cmd, char **envp)
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

/**
 * Runs the @param cmd command
 */
void	run_command(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(argv[0], '.'))
		cmd_not_found(argv, NULL);
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
		cmd_not_found(argv, path);
	if (execve(path, argv, envp) < 0)
	{
		free_split(argv);
		error();
	}
	free(path);
}

/**
 * Runs the first command reading the content of the infile file
 */
void	run_first_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		close_fds(fds);
		return ;
	}
	ft_dup2(fd, STDIN_FILENO);
	ft_dup2(fds[1], STDOUT_FILENO);
	close_fds(fds);
	run_command(av[2], envp);
}

/**
 * Runs the last command reading the output of the first cmd
 * and writing its output in the outfile file
 */
void	run_last_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		error();
	ft_dup2(fds[0], STDIN_FILENO);
	ft_dup2(fd, STDOUT_FILENO);
	close_fds(fds);
	run_command(av[3], envp);
}
