/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:51 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 07:51:30 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (--ac)
// 	{
// 		printf("char: %c\n", av[i][0]);
// 		printf("ft_tolower: %c\n", ft_tolower(av[i][0]));
// 		printf("tolower: %c\n---\n", tolower(av[i][0]));
// 		++i;
// 	}
// 	return (0);
// }