/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:45:48 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/10 12:34:56 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *s, size_t i)
{
	return (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'));
}

int	ft_atoi(const char *nptr)
{
	int		result;
	int		negative;
	size_t	i;

	result = 0;
	negative = 0;
	i = 0;
	while (ft_isspace(nptr, i))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			++negative;
	while (ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - '0');
	if (negative)
		return (-result);
	return (result);
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		negative;
	size_t	i;

	result = 0;
	negative = 0;
	i = 0;
	while (ft_isspace(nptr, i))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			++negative;
	while (ft_isdigit(nptr[i]))
		result = result * 10 + (nptr[i++] - '0');
	if (negative)
		return (-result);
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// int main(int ac, char **av)
// {
// 	int i = 1;
// 	while (--ac)
// 	{
// 		printf("ft_atoi: %d\n", ft_atoi(av[i]));
// 		printf("atoi: %d\n---\n", atoi(av[i]));
// 		assert(ft_atoi(av[i]) == atoi(av[i]));
// 		++i;
// 	}
// 	return (0);
// }