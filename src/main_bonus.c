/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:25 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Function executed by the child process
 */
static void	child_process(int ac, char **av, char **envp, t_pipex *pipex)
{
	if (pipex->pipe_prev[0] != -1)
		ft_dup2(pipex->pipe_prev[0], STDIN_FILENO);
	else
		ft_dup2(pipex->infile, STDIN_FILENO);
	if (pipex->i != ac - 2)
		ft_dup2(pipex->pipe_curr[1], STDOUT_FILENO);
	else
		ft_dup2(pipex->outfile, STDOUT_FILENO);
	close_fds(pipex->pipe_prev);
	if (pipex->i != ac - 2)
		close_fds(pipex->pipe_curr);
	close_files(pipex->infile, pipex->outfile);
	run_command(av[pipex->i], envp);
	exit(1);
}

/**
 * Creates a child process to run the command
 */
static void	create_child(int ac, char **av, char **envp, t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid < 0)
		error();
	if (pipex->pid == 0)
		child_process(ac, av, envp, pipex);
}

int	here_doc_bonus(int ac, char **av, char **envp)
{
	(void)ac, (void)av, (void)envp;
	t_here_doc	here_doc;
	printf("here_doc functionality to be implemented\n");
	// ? 1. Implement here_doc functionality
	// ? 1.1 Use GNL to read from stdin until the limiter is found
	here_doc.limiter = av[2];
	here_doc.args = ft_split(av[3], ' ');
	here_doc.size = -1;
	while (here_doc.args[++here_doc.size])
		;
	ft_readline(&here_doc);
	for (int i = 0; here_doc.args[i]; i++)
		printf("heredoc_args[%d]: %s\n", i, here_doc.args[i]);
	// ? 1.2 Write the input to a temporary file
	// ? 1.3 Use the temporary file as infile for the first command
	// ? 1.4 Unlink the temporary file after use
	// ? 2. Proceed with the rest of the pipex logic, reusing loop_bonus if possible and modifying outfile handling to append mode (just adding a flag to the corresponding open call)
	// ? 2.1 Open file
	// ? 3. fork and execve with heredoc_args as input
	free_split(here_doc.args);
	return (0);
}

int	loop_bonus(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	init_pipex(ac, av, &pipex);
	init_pipe_ends(pipex.pipe_prev);
	pipex.i = 2;
	while (pipex.i < ac - 1)
	{
		if (pipex.i != ac - 2
			&& pipe(pipex.pipe_curr) < 0)
			error();
		create_child(ac, av, envp, &pipex);
		close_fds(pipex.pipe_prev);
		if (pipex.i != ac - 2)
			update_pipe_ends(pipex.pipe_prev, pipex.pipe_curr);
		pipex.i++;
	}
	close_fds(pipex.pipe_prev);
	close_files(pipex.infile, pipex.outfile);
	while (wait(NULL) > 0)
		;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	if (ft_equals(av[1], "here_doc") && ac == 6)
		return (here_doc_bonus(ac, av, envp));
	else if (ac >= 5)
		return (loop_bonus(ac, av, envp));
	ft_error("Error: Invalid number of arguments");
	return (1);
}
