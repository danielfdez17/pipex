/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:03 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 12:21:58 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strdup(const char *s)
// {
// 	size_t	i;
// 	char	*dup;

// 	i = 0;
// 	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (!dup)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		++i;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// TODO: test ft_memmove version
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = ft_calloc((len + 1), sizeof(char));
	if (!dup)
		return (NULL);
	return (ft_memmove(dup, s, len + 1));
}
