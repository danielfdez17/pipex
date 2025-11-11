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
# include "../libft/inc/headers/libft.h"
# include "../libft/inc/headers/ft_printf.h"

// * ERROR HANDLERS
void	error_bonus(void);
void	cmd_not_found_bonus(char **argv, char *path);

// * FILES HANDLERS
void	close_fds_bonus(int *fds);
int		open_read_file_bonus(char *filename);
int		open_write_file_bonus(char *filename);
void	ft_dup2_bonus(int oldfd, int newfd);

// * MEMORY HANDLERS
void	free_split_bonus(char **split);

// * COMMANDS HANDLERS
char	*get_path_bonus(char *cmd, char **envp);
void	run_command_bonus(char *cmd, char **envp);
void	run_i_cmd_bonus(char **av, int *fds, char **envp, int cmd);

#endif // PIPEX_BONUS_H