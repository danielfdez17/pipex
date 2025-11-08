#include "../inc/headers/pipex.h"

void	run_command(char *cmd, char *envp[])
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	if (cmd_have_current_path(cmds[0]))
	{
		free_split(cmds);
		ft_putendl_fd("No such file or directory\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (cmd_have_path(cmds[0]))
	{
		path = ft_strdup(cmds[0]);
		if (execve(path, cmds, envp) < 0)
			error();
		return ;
	}
	path = get_path(cmds[0], envp);
	if (!path)
	{
		free_split(cmds);
		ft_putendl_fd("No such file or directory\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmds, envp) < 0)
		error();
}

void	run_i_child(t_pipex *pipex, int fd_read, char *envp[])
{
	close(pipex->fds[0]);
	ft_dup2(fd_read, STDIN_FILENO);
	ft_dup2(pipex->fds[1], STDOUT_FILENO);
	run_command(pipex->cmd1, envp);
}

void	run_last_child(t_pipex *pipex, int fd_write, char *envp[])
{
	ft_dup2(pipex->fds[0], STDIN_FILENO);
	ft_dup2(fd_write, STDOUT_FILENO);
	run_command(pipex->cmd2, envp);
}

// void	run_command(char *cmd, char **envp)
// {
// 	char	**split_cmd;
// 	char	*executable;

// 	split_cmd = ft_split(cmd, ' ');
// 	if (!split_cmd)
// 	{
// 		ft_putendl_fd("Command could not be splitted", STDERR_FILENO);
// 		error();
// 	}
// 	executable = get_exetuable(split_cmd[0]);

// 	if (execve(executable, split_cmd, envp) < 0)
// 	{
// 		free(split_cmd);
// 		free(executable);
// 		error();
// 	}
// 	free(split_cmd);
// 	free(executable);
// }


// void	run_i_child(t_pipex *pipex, int fd_read)
// {
// 	close(pipex->fds[0]);
// 	ft_dup2(fd_read, STDIN_FILENO);
// 	ft_dup2(pipex->fds[1], STDOUT_FILENO);
// 	run_command(pipex->cmd1, pipex->envp);
// 	// close_fds(pipex->fds);
// 	// close(fd_read);
// }

// void	run_last_child(t_pipex *pipex, int fd_write)
// {
// 	ft_dup2(pipex->fds[0], STDIN_FILENO);
// 	ft_dup2(fd_write, STDOUT_FILENO);
// 	run_command(pipex->cmd2, pipex->envp);
// 	// close_fds(pipex->fds);
// 	// close(fd_write);
// 	// close(pipex->fds[1]);
// }