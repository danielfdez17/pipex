/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:52 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/07 10:25:39 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len = ft_min(len, ft_strlen(s) - start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		ptr[i] = s[start];
		++i;
		++start;
	}
	ptr[i] = '\0';
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	// printf("%s\n", ft_substr("hola", 0, 18446744073709551615ULL));
// 	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 0, 10));
// 	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
// 	printf("%s\n", ft_substr("tripouille", 0, 42000));
// 	printf("%s\n", ft_substr("0123456789", 9, 10));
// 	return (0);
// }
// // ccw ft_substr.c ft_strlen.c ft_strdup.c -o a.out && ./a.out
