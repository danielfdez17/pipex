/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:09 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:27:43 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

void	run_command(t_pipex *pipex, char *cmd, char **envp)
{
	char	**split_cmd;
	char	*executable;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
	{
		ft_putendl_fd("Command could not be splitted", STDERR_FILENO);
		error(pipex);
	}
	executable = get_exetuable(split_cmd[0]);

	if (execve(executable, split_cmd, envp) < 0)
	{
		free(split_cmd);
		free(executable);
		error(pipex);
	}
	free(split_cmd);
	free(executable);
}


void	run_i_child(t_pipex *pipex, int fd_read)
{
	close(pipex->fds[0]);
	ft_dup2(pipex, fd_read, STDIN_FILENO);
	ft_dup2(pipex, pipex->fds[1], STDOUT_FILENO);
	run_command(pipex, pipex->cmd1, pipex->envp);
	// close_fds(pipex->fds);
	// close(fd_read);
}

void	run_last_child(t_pipex *pipex, int fd_write)
{
	ft_dup2(pipex, pipex->fds[0], STDIN_FILENO);
	ft_dup2(pipex, fd_write, STDOUT_FILENO);
	run_command(pipex, pipex->cmd2, pipex->envp);
	// close_fds(pipex->fds);
	// close(fd_write);
	// close(pipex->fds[1]);
}