/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:06:31 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 08:13:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

/**
 * Prints the error and terminates the program execution
 */
void	error(void)
{
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
