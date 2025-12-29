/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:04 by danfern3          #+#    #+#             */
/*   Updated: 2025/12/29 08:20:37 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if (c > 255)
		c %= 256;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (c == '\0')
		return (ptr);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// #include <assert.h>
// int main(void)
// {
// 	const char *s = "bonjour";
// 	int c = 'b';
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	c = 'o';
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	c = 'j';
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	c = 's';
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	c = '\0';
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	s = "";
// 	assert(ft_strchr(s, c) == strchr(s, c));
// 	// printf("ft_strchr: %s\n", ft_strchr(s, c));
// 	// printf("strchr: %s\n---\n", strchr(s, c));
// 	return (0);
// }