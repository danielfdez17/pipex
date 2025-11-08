/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:59 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 15:52:32 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dsize == 0)
		return (src_size);
	i = 0;
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size);
}

// #include <stdio.h>
// // #include <bsd/string.h>
// int main(void)
// {
// 	const char *src = "lorem ipsum dolor sit amet";
// 	char *dest = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
// 	size_t dsize = 0;
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("ft_strlcpy: %ld\n", ft_strlcpy(dest, src, dsize));
// 	// printf("strlcpy: %zu\n", strlcpy(dest, src, dsize));
// 	return (0);
// }
