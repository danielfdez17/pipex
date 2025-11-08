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
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		ptr[i] = s[start];
		++i;
		++start;
	}
	return (ptr);
}
