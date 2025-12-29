/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:32:07 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 15:27:49 by danfern3         ###   ########.fr       */
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
# include "libft.h"

// * ERROR HANDLERS
void	error(void);
void	cmd_not_found(char **argv, char *path);

// * FILES HANDLERS
void	close_fds(int *fds);
int		open_read_file(char *filename);
int		open_write_file(char *filename);
void	ft_dup2(int oldfd, int newfd);

// * MEMORY HANDLERS
void	free_split(char **split);

// * COMMANDS HANDLERS
char	*get_path(char *cmd, char **envp);
void	run_command(char *cmd, char **envp);
int		run_first_cmd(char **av, int *fds, char **envp);
int		run_last_cmd(char **av, int *fds, char **envp);

#endif // PIPEX_H