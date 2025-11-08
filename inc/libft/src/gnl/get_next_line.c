/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:42 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/24 08:24:13 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = ft_calloc(size, sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	while (s2 && s2[j])
		result[i++] = s2[j++];
	free(s1);
	free(s2);
	return (result);
}

static char	*clean_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

static char	*ft_till_endl(char *s)
{
	size_t	new_size;

	if (!s || !s[0])
		return (NULL);
	new_size = 0;
	while (s[new_size])
	{
		if (s[new_size] == '\n')
			return (ft_substr(s, 0, new_size + 1));
		++new_size;
	}
	return (ft_substr(s, 0, new_size));
}

static char	*ft_read_file(int fd, char *static_buff)
{
	char				*buffer;
	ssize_t				bytes;
	unsigned long long	buffer_size;

	buffer_size = BUFFER_SIZE;
	bytes = 1;
	while (!ft_strchr(static_buff, '\n') && bytes > 0)
	{
		buffer = malloc(sizeof(char) * (buffer_size + 1));
		if (!buffer)
			return (buffer);
		bytes = read(fd, buffer, buffer_size);
		if (bytes == -1)
		{
			free(buffer);
			free(static_buff);
			return (NULL);
		}
		buffer[bytes] = '\0';
		static_buff = ft_strjoin_gnl(static_buff, buffer);
		buffer_size *= 2;
	}
	return (static_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_till_endl(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
