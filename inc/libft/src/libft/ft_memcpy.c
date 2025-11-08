/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:11 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 13:55:11 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (n == 0 || dest == src)
		return (dest);
	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		++i;
	}
	return (dest);
}
