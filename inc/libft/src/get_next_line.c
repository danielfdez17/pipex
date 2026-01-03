/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:42 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/29 15:35:57 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	new_buffer = malloc(ft_strlen_gnl(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
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
			return (ft_substr_gnl(s, 0, new_size));
		++new_size;
	}
	return (ft_substr_gnl(s, 0, new_size));
}

static char	*ft_read_file(int fd, char *static_buff)
{
	char				*buffer;
	ssize_t				bytes;
	unsigned long long	buffer_size;

	buffer_size = BUFFER_SIZE;
	bytes = 1;
	while (!ft_strchr_gnl(static_buff, '\n') && bytes > 0)
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

char	*get_next_line(int fd, int free_static_buff)
{
	static char	*buffer;
	char		*line;

	if (free_static_buff == 1)
	{
		free(buffer);
		return (NULL);
	}
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_till_endl(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
