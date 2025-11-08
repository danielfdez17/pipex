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
