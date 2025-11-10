/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:08:16 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:28:59 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/headers/pipex.h"

t_bool	validate_commands(t_pipex *pipex, int ac, char **av)
{
	int		i;
	char	*executable;
	char	**cmd;
	int		access_res;
	
	i = 2;
	while (i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		if (!cmd)
		{
			ft_putendl_fd("Could not split av when validating commands", STDERR_FILENO);
			error(pipex);
		}
		executable = get_exetuable(cmd[0]);
		access_res = access(executable, F_OK);
		free(executable);
		free_split(cmd);
		if (access_res != 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
