/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:25:36 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

/**
 * Prints the error and terminates the program execution
 */
bool	error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
	return (false);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(RED "pipex_bonus: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(RESET "\n", STDERR_FILENO);
}

/**
 * Frees the memory used by @param argv and @param path,
 * prints an error msg and terminates the program
 */
void	cmd_not_found(char **argv, char *path)
{
	perror(NULL);
	if (path)
		free(path);
	path = NULL;
	if (argv)
		free_split(argv);
	exit(errno);
}
