/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/03 07:45:57 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_equals(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s1_len = ft_max((int)s1_len, (int)s2_len);
	return (!ft_strncmp(s1, s2, s1_len + 1));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		++i;
	}
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int main(void)
// {
// 	const char *s1 = "owieuralksdjf";
// 	const char *s2 = "ualksdjf";
// 	size_t c = 7;
// 	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, c));
// 	printf("strncmp: %d\n---\n", strncmp(s1, s2, c));
// 	return (0);
// }