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

#include "../inc/headers/pipex.h"

/**
 * Prints the error and terminates the program execution
 */
void	error(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(errno);
}

/**
 * Frees the memory used by @param argv and @param path,
 * prints an error msg and terminates the program
 */
void	cmd_not_found(char **argv, char *path)
{
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	if (path)
		free(path);
	path = NULL;
	if (argv)
		free_split(argv);
	exit(errno);
}