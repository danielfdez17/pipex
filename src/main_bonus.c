/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:07:54 by danfern3          #+#    #+#             */
/*   Updated: 2026/01/05 08:16:24 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 6 && ft_equals(av[1], "here_doc"))
		return (here_doc_bonus(ac, av, envp));
	else if (ac >= 5)
		return (loop_bonus(ac, av, envp));
	ft_error("Error: Invalid number of arguments");
	return (1);
}
