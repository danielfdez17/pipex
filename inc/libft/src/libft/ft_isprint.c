/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:14 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 08:12:24 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (ac-- > 1)
// 	{
// 		printf("char: %c\n", av[i][0]);
// 		printf("isprint: %d\n", isprint(av[i][0]));
// 		printf("ft_isprint: %d\n---\n", ft_isprint(av[i][0]));
// 		++i;
// 	}
// 	return (0);
// }