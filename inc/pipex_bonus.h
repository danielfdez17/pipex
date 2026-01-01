/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:32:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:38 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "colors.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pipe_prev[2];
	int		pipe_curr[2];
	pid_t	pid;
	int		i;
}	t_pipex;

typedef struct s_here_doc
{
	char	*limiter;
	char	**args;
	int		size;
}	t_here_doc;

// * ERROR HANDLERS
bool	error(void);
void	ft_error(char *msg);
void	cmd_not_found(char **argv, char *path);

// * FILES HANDLERS
void	close_fds(int *fds);
// ! NO
// int		open_read_file(char *filename);
// ! NO
// int		open_write_file(char *filename);
void	ft_dup2(int oldfd, int newfd);
void	init_pipe_ends(int fds[2]);
void	update_pipe_ends(int prev[2], int curr[2]);
void	close_files(int infile, int outfile);

// * MEMORY HANDLERS
void	free_split(char **split);

// * COMMANDS HANDLERS
char	*get_path(char *cmd, char **envp);
// ! NO
// int		run_first_cmd(char **av, int *fds, char **envp);
// ! NO
// int		run_last_cmd(int ac, char **av, int *fds, char **envp);
void	run_command(char *cmd, char **envp);
void	search_path(char **envp, int *i);
// ! NO
// void	run_i_cmd(char **av, char **envp, int cmd);

// * PIPEX STRUCT HANDLERS
bool	init_pipex(int ac, char **av,t_pipex *pipex);


char	**ft_realloc(char **av, char *line, int size, bool free_line);
void	ft_readline(t_here_doc *heredoc);

#endif // PIPEX_BONUS_H