/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:03 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 08:08:06 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

char	*get_exetuable(char *program_name)
{
	return (ft_strjoin("/usr/bin/", program_name));
}

void	execute(char *first, char *second, int *fds)
{
	pid_t		pid1;
	pid_t		pid2;
	char		**av1;
	char		**av2;
	char		*exec_name1;
	char		*exec_name2;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("First process could not have been forked\n");
		return ;
	}
	if (pid1 == 0)
	{
		av1 = ft_split(first, ' ');
		if (!av1)
			return ;
		exec_name1 = get_exetuable(av1[0]);
		dup2(fds[1], STDOUT_FILENO);
		close_fds(fds);
		if (execve(exec_name1, av1, NULL) == -1)
		{
			perror("Could not execute execve");
			return ;
		}
		free_split(av1);
		free(exec_name1);
	}

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("Second process could not have been forked\n");
		return ;
	}
	if (pid2 == 0)
	{
		av2 = ft_split(second, ' ');
		if (!av2)
			return ;
		exec_name2 = get_exetuable(av2[0]);
		dup2(fds[0], STDIN_FILENO);
		close_fds(fds);
		if (execve(exec_name2, av2, NULL) == -1)
		{
			perror("Could not execute execve");
			return ;
		}
		// free_split(av2);
		// free(exec_name2); 
	}
	close_fds(fds);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

// void	pipex(int ac, char **av, int fd_read, int fd_write)
// {
// 	int		i;
// 	int		pid_ptr;
// 	int		size;
// 	int		fds[2];
// 	pid_t	*pids;

// 	(void)fd_read;
// 	(void)fd_write;
// 	if (!validate_commands(ac, av))
// 	{
// 		ft_printf("There is an invalid command\n");
// 		return ;
// 	}
// 	i = 2;
// 	size = ac - i - 1;
// 	pids = malloc(sizeof(pid_t) * size);
// 	if (!pids)
// 	{
// 		ft_printf("Could not allocate memory for pids\n");
// 		return ;
// 	}
// 	pid_ptr = 0;
// 	ft_printf("size: %d\n", size);
// 	while (pid_ptr < size)
// 	{
// 		pids[pid_ptr] = fork();
// 		if (pids[pid_ptr] < 0)
// 		{
// 			free(pids);
// 			return ;
// 		}
// 		if (pids[pid_ptr] == 0)
// 		{
// 			ft_printf("Hi my pid is %d\n", pids[pid_ptr]);
// 		}
// 		pid_ptr++;
// 	}
// 	return ;

// 	// ! leer con GNL el fd_read y escribir en el pipe de escritura (fds[1])
// 	if (pipe(fds) == -1)
// 	{
// 		perror("Pipe could not have been initialized\n");
// 		return ;
// 	}
// 	i = 2;
// 	while (i < ac - 2)
// 	{
// 		execute(av[i], av[i + 1], fds);
// 		++i;
// 	}
// 	close_fds(fds);
// 	close(fd_read);
// 	close(fd_write);
// }

