/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	main_heredoc(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(fds) == -1)
		error();
	pid1 = fork();
	if (pid1 < 0)
		error();
	if (pid1 == 0)
		run_first_cmd(av, fds, envp);
	pid2 = fork();
	if (pid2 < 0)
		error();
	if (pid2 == 0)
		run_last_cmd(ac, av, fds, envp);
	close_fds(fds);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

int	here_doc_bonus(int ac, char **av, char **envp)
{
	(void)ac, (void)av, (void)envp;
	t_here_doc	heredoc;
	heredoc.limiter = av[2];
	heredoc.args = ft_split(av[3], ' ');
	heredoc.size = -1;
	while (heredoc.args[++heredoc.size])
		;
	ft_readline(&heredoc);
	// for (int i = 0; heredoc.args[i]; i++)
	// 	printf("heredoc_args[%d]: %s\n", i, heredoc.args[i]);
	main_heredoc(ac, av, envp);
	free_split(heredoc.args);
	return (0);
}
