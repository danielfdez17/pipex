/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:09 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:36:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex_bonus.h"

/**
 * @returns the path stored in @param envp
 */
char	*get_path_bonus(char *cmd, char **envp)
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
			free_split_bonus(split_path);
			return (path);
		}
		free(path);
		i++;
	}
	free_split_bonus(split_path);
	return (NULL);
}

/**
 * Runs the @param cmd command
 */
void	run_command_bonus(char *cmd, char **envp)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (ft_strchr(argv[0], '.'))
		cmd_not_found_bonus(argv, NULL);
	if (ft_strchr(argv[0], '/'))
	{
		path = ft_strdup(argv[0]);
		if (execve(path, argv, envp) < 0)
		{
			free_split_bonus(argv);
			free(path);
			error_bonus();
		}
	}
	path = get_path_bonus(argv[0], envp);
	if (!path)
		cmd_not_found_bonus(argv, path);
	if (execve(path, argv, envp) < 0)
	{
		free_split_bonus(argv);
		error_bonus();
	}
	free(path);
}

/**
 * Runs the @param cmd command reading
 */
void	run_i_cmd_bonus(char **av, int *fds, char **envp, int cmd)
{
	pid_t	pid;

	if (pipe(fds) < 0)
		error_bonus();
	pid = fork();
	if (pid < 0)
		error_bonus();
	if (pid == 0)
	{
		ft_dup2_bonus(fds[1], STDOUT_FILENO);
		close(fds[0]);
		run_command_bonus(av[cmd], envp);
	}
	else
	{
		ft_dup2_bonus(fds[0], STDIN_FILENO);
		close(fds[1]);
		waitpid(pid, NULL, 0);
	}
}
