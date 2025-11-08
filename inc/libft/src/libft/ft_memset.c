/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:09 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/06 13:29:24 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// #include "libft.h"
// int main(void)
// {
// 	char *str = ft_strdup("hola buenas");
// 	// printf("memset: %s\n", (char *)memset(str, 'a', 3));
// 	printf("ft_memset: %s\n", (char *)ft_memset(str, 'a', 3));
// 	if (str)
// 		free(str);
// 	return (0);
// }
// ccw ft_memset.c ft_strdup.c ft_strlen.c -o a.out && ./a.out