/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:44 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/24 08:24:09 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strjoin_gnl(char *s1, char *s2)
// {
// 	char	*result;
// 	size_t	size;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	result = malloc(sizeof(char) * size);
// 	if (!result)
// 		return (NULL);
// 	while (s1 && s1[i])
// 	{
// 		result[i] = s1[i];
// 		++i;
// 	}
// 	while (s2 && s2[j])
// 		result[i++] = s2[j++];
// 	result[i] = '\0';
// 	free(s1);
// 	free(s2);
// 	return (result);
// }

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	i;
// 	size_t	size_s;

// 	size_s = ft_strlen(s);
// 	if (!s || start > size_s)
// 		return (NULL);
// 	if (len > size_s - start)
// 		len = size_s - start;
// 	ptr = malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (s[start] != '\0' && i < len)
// 	{
// 		ptr[i] = s[start];
// 		++i;
// 		++start;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }
