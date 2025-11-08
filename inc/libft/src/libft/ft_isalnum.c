/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:18 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 12:21:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <ctype.h>
// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (ac-- > 1)
// 	{
// 		printf("char: %c\n", av[i][0]);
// 		printf("isalnum: %d\n", isalnum(av[i][0]));
// 		printf("ft_isalnum: %d\n---\n", ft_isalnum(av[i][0]));
// 		++i;
// 	}
// 	return (0);
// }