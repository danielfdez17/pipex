/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:00 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/07 08:45:59 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;
	size_t	src_size;
	size_t	dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	i = dst_size;
	j = 0;
	if (dsize <= dst_size)
		return (src_size + dsize);
	while (src[j] && j < (dsize - dst_size - 1))
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = '\0';
	return (src_size + dst_size);
}

// #include <stdio.h>
// #include <string.h>
// #include <bsd/string.h>
// #include <assert.h>
// int main(void)
// {
// 	printf("ft_strlcat: %ld\n", ft_
// strlcat(ft_strdup("pqrstuvwxyz"), ft_strdup("abcd"), 20));
// 	printf("   strlcat: %ld\n---\n", 
// strlcat(ft_strdup("pqrstuvwxyz"), ft_strdup("abcd"), 20));
// 	printf("ft_strlcat: %ld\n", ft_
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 10));
// 	printf("   strlcat: %ld\n---\n", 
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 10));
// 	printf("ft_strlcat: %ld\n", ft_
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 11));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 11));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 12));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 12));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 13));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 13));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 14));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 14));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 15));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 15));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 16));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 16));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 17));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrs"), ft_strdup("abcdefghi"), 17));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("pqrstuvwxyz"), ft_strdup("abcd"), 20));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("pqrstuvwxyz"), ft_strdup("abcd"), 20));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("rrrrrr\0\0\0\0a"), ft_strdup("lorem"), 15));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("rrrrrr\0\0\0\0a"), ft_strdup("lorem"), 15));
// 	printf("ft_strlcat: %ld\n", ft
// strlcat(ft_strdup("\0rrrrr\0\0\0\0a\0\0a"), ft_strdup("lorem ipsum"), 15));
// 	printf("   strlcat: %ld\n---\n",
// strlcat(ft_strdup("\0rrrrr\0\0\0\0a\0\0a"), ft_strdup("lorem ipsum"), 15));
// 	return (0);
// }
// // ccw -lbsd ft_strlcat.c ft_strlen.c ft_strdup.c -o a.out && ./a.out