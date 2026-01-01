/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:44 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/27 11:27:48 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	while (s2 && s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	free(s2);
	return (result);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		++i;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size_s;

	size_s = ft_strlen_gnl(s);
	if (!s || start > size_s)
		return (NULL);
	if (len > size_s - start)
		len = size_s - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
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
