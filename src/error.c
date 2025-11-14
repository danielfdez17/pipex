/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/14 15:32:45 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * Prints the error and terminates the program execution
 */
void	error(void)
{
	// ft_putendl_fd(strerror(errno), STDERR_FILENO);
	perror(NULL);
	exit(EXIT_FAILURE);
}

/**
 * Frees the memory used by @param argv and @param path,
 * prints an error msg and terminates the program
 */
void	cmd_not_found(char **argv, char *path)
{
	perror(NULL);
	// ft_putstr_fd(" ", STDERR_FILENO);
	// ft_putstr_fd(argv[0], STDERR_FILENO);
	if (path)
		free(path);
	path = NULL;
	if (argv)
		free_split(argv);
	exit(errno);
}
