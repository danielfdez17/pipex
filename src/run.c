/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:09 by danfern3          #+#    #+#             */
/*   Updated: 2026/01/05 08:12:56 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	search_path(char **envp, int *i)
{
	*i = 0;
	while (ft_strncmp(envp[*i], "PATH", 4))
		(*i)++;
}

/**
 * @returns the path stored in @param envp
 */
char	*get_path(char *cmd, char **envp)
{
	char	**split_path;
	char	*path;
	char	*tmp;
	int		i;

	if (!envp || !*envp)
		return (NULL);
	search_path(envp, &i);
	split_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
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
		if (execve(argv[0], argv, envp) < 0)
		{
			free_split(argv);
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
int	run_first_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	if (access(av[1], F_OK) != 0)
	{
		close_fds(fds);
		error();
	}
	if (access(av[1], R_OK) != 0)
	{
		close_fds(fds);
		error();
	}
	fd = open(av[1], O_RDONLY, 0644);
	if (fd < 0)
	{
		close_fds(fds);
		error();
	}
	ft_dup2(fd, STDIN_FILENO);
	ft_dup2(fds[1], STDOUT_FILENO);
	close_fds(fds);
	run_command(av[2], envp);
	return (0);
}

/**
 * Runs the last command reading the output of the first cmd
 * and writing its output in the outfile file
 */
int	run_last_cmd(char **av, int *fds, char **envp)
{
	int	fd;

	if (errno != 0)
		return (errno);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		error();
	ft_dup2(fds[0], STDIN_FILENO);
	ft_dup2(fd, STDOUT_FILENO);
	close_fds(fds);
	run_command(av[3], envp);
	return (0);
}
