/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:55 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/07 09:53:14 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *litle, size_t len)
{
	size_t	i;
	size_t	j;

	if (litle[0] == '\0')
		return (&big[0]);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == litle[j] && i + j < len)
		{
			if (litle[j + 1] == '\0')
				return (&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
