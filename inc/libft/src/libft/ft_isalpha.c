/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:17 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 13:12:12 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') \
		|| (c >= 'A' && c <= 'Z'))
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
// 		printf("isalpha: %d\n", isalpha(av[i][0]));
// 		printf("ft_isalpha: %d\n---\n", ft_isalpha(av[i][0]));
// 		++i;
// 	}
// 	return (0);
// }