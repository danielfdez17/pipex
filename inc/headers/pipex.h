/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:32:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:38:38 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif

typedef short int	t_bool;

typedef struct s_pipex
{
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	int		fd_read;
	int		fd_write;
}	t_pipex;

// * ERROR HANDLERS
void	error(void);
void	cmd_not_found(char **argv, char *path);
// void	error(t_pipex *pipex);

// * FILES HANDLERS
void	ft_dup2(int oldfd, int newfd);
void	close_fds(int *fds);
// void	close_fds(t_pipex *pipex);
int		open_read_file(char *filename);
int		open_write_file(char *filename);

// * MEMORY HANDLERS
void	free_split(char **split);

// * COMMANDS HANDLERS
void	run_command(char *cmd, char **envp);
// void	run_command(t_pipex *pipex, char *cmd, char **envp);
char	*get_exetuable(char *program_name);
t_bool	validate_commands(t_pipex *pipex, int ac, char **av);

#endif // PIPEX_H